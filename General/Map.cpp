#include "Map.h"

#include <math.h>

Map::Map()
	:width(Configure::mapWidth), height(Configure::mapHeight)
{
	floor = Configure::floorSprite;

	map = new bool* [height];
	walls = new Wall** [height];
	for (int i = 0; i < height; i++) {
		map[i] = new bool[width];
		walls[i] = new Wall * [width];
		for (int j = 0; j < width; j++) {
			int ii = i * Configure::mapHeightStart / height;
			int jj = j * Configure::mapWidthStart / width;

			map[i][j] = Configure::map[ii][jj];

			float x = j * Configure::wallWidth;
			float y = i * Configure::wallWidth;
			if (map[i][j])
				walls[i][j] = new Wall(x, y);
			else
				walls[i][j] = nullptr;
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
			if (walls[i][j])
				walls[i][j]->Draw(window);
			else {
				floor.setPosition(sf::Vector2f((j+0.7) * Configure::wallWidth, (i+0.7)*Configure::wallWidth));
				window.draw(floor);
			}
				
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

Wall& Map::operator()(int row, int column)
{
	return *walls[row][column];
}

bool* Map::operator[](int row)
{
	return map[row];
}
