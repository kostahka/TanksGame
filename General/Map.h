#pragma once

#include "../Configurations/Configure.h"
#include "../GameObjects/Wall.h"

struct MapElement {
	int row;
	int column;
	bool collide;
};

class Map {
public:
	Map();
	~Map();

	void GenerateMap();

	int getWidth() const;
	int getHeight() const;
	void Draw(sf::RenderWindow& window);
	void DrawForeGround(sf::RenderWindow& window);

	void Hurt(int damage, int row, int column);

	sf::Vector2f getRandomPlaceToSpawn();

	bool getSea(int row, int column);

	Wall& operator() (int row, int column);
	bool* operator[] (int row);
private:
	int width;
	int height;

	sf::Sprite floor;
	Wall*** walls;
	bool** sea;
	bool** map;
};