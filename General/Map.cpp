#include "Map.h"

#include <math.h>
#include "PerlinNoise.hpp"

Map::Map()
	:width(Configure::mapWidth), height(Configure::mapHeight)
{
	floor = Configure::floorSprite;

	map = new bool* [height];
	sea = new bool* [height];
	walls = new Wall** [height];
	for (int i = 0; i < height; i++) {
		map[i] = new bool[width];
		sea[i] = new bool[width];
		walls[i] = new Wall * [width];
		for (int j = 0; j < width; j++) {
			sea[i][j] = false;
			map[i][j] = false;
			walls[i][j] = nullptr;
		}
	}

	GenerateMap();
}

Map::~Map()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete walls[i][j];
		}
		delete[] walls[i];
		delete[] sea[i];
		delete[] map[i];
	}
	delete[] walls;
	delete[] sea;
	delete[] map;
}

void Map::GenerateMap()
{
	siv::PerlinNoise::seed_type seed = rand();
	siv::PerlinNoise perlin{ seed };

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			map[i][j] = false;
			sea[i][j] = false;
			delete walls[i][j];
			walls[i][j] = nullptr;

			float x = j * Configure::wallWidth;
			float y = i * Configure::wallWidth;

			if (i < 2 || j < 2 || i > height - 3 || j > width - 3) {
				map[i][j] = true;
				walls[i][j] = new Wall(WallType::Wall, x, y);
			}
			else {
				float wallRoll = perlin.normalizedOctave2D_01(i / 2, j / 2, 3);
				//float wallRoll = perlin.noise2D_01(i / 2, j / 2);

				if (wallRoll < Configure::mapWallsFill) {
					map[i][j] = true;

					if(wallRoll < Configure::mapImmortalWallsFill)
						walls[i][j] = new Wall(WallType::Immortal, x, y);
					else
						walls[i][j] = new Wall(WallType::Wall, x, y);
				}
				else {
					float grassRoll = perlin.normalizedOctave2D_01(height + i / 2, width + j / 2, 3);
					//float grassRoll = perlin.noise2D_01(height + i / 2, width + j / 2);
					if (grassRoll < Configure::mapGrassFill) {
						walls[i][j] = new Wall(WallType::Grass, x, y);
					}
					else {
						float waterRoll = perlin.normalizedOctave2D_01(2 * height + i / 2, 2 * width + j / 2, 3);
						//float waterRoll = perlin.noise2D_01(2 * height + i / 2, 2 * width + j / 2);
						if (waterRoll < Configure::mapWaterFill) {
							walls[i][j] = new Wall(WallType::Water, x, y);
							sea[i][j] = true;
						}
					}
				}
			}

			/*int ii = i * Configure::mapHeightStart / height;
			int jj = j * Configure::mapWidthStart / width;

			map[i][j] = Configure::map[ii][jj];

			float x = j * Configure::wallWidth;
			float y = i * Configure::wallWidth;
			if (map[i][j]) {
				WallType type = WallType(rand() % 4);
				if (type == WallType::Water) {
					map[i][j] = false;
					sea[i][j] = true;
				}
				else if (type == WallType::Grass)
					map[i][j] = false;
				walls[i][j] = new Wall(type, x, y);
			}
			else
				walls[i][j] = nullptr;*/
		}
	}
}

int Map::getWidth() const
{
	return width;
}

int Map::getHeight() const
{
	return height;
}

void Map::Draw(sf::RenderWindow& window)
{
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (walls[i][j] && walls[i][j]->getType() != WallType::Grass)
				walls[i][j]->Draw(window);
			else {
				floor.setPosition(sf::Vector2f((j+0.5) * Configure::wallWidth, (i+0.5)*Configure::wallWidth));
				window.draw(floor);
			}	
		}
	}
}

void Map::DrawForeGround(sf::RenderWindow& window)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (walls[i][j] && walls[i][j]->getType() == WallType::Grass)
				walls[i][j]->Draw(window);
		}
	}
}

void Map::Hurt(int damage, int row, int column)
{
 	if (walls[row][column]->Hurt(damage)) {
		walls[row][column] = nullptr;
		map[row][column] = false;
	}
}

sf::Vector2f Map::getRandomPlaceToSpawn()
{
	int step = ceil(Configure::tankWidth / Configure::wallWidth);
	int randPlace = rand() % (width * height / step);
	while (randPlace > 0) {
		for (int i = 0; i < height - step; i++) {
			for (int j = 0; j < width - step; j++) {
				bool canPlace = true;
				for (int r = i; r < i + step; r++) {
					for (int c = j; c < j + step; c++) {
						if (walls[r][c]) {
							canPlace = false;
							break;
						}
					}
					if (!canPlace)
						break;
				}
				if (canPlace)
				{
					randPlace--;
					if (randPlace <= 0) {
						float delta = (Configure::wallWidth * step - Configure::tankWidth) / 2;
						return sf::Vector2f(j * Configure::wallWidth + delta, i * Configure::wallWidth + delta);
					}
				}
			}
		}
	}
	return sf::Vector2f();
}

bool Map::getSea(int row, int column)
{
	return sea[row][column];
}

Wall& Map::operator()(int row, int column)
{
	return *walls[row][column];
}

bool* Map::operator[](int row)
{
	return map[row];
}
