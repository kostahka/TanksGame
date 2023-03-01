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

	int getWidth() const;
	int getHeight() const;
	void Draw(sf::RenderWindow& window);

	void Hurt(int damage, int row, int column);

	Wall& operator() (int row, int column);
	bool* operator[] (int row);
private:
	int width;
	int height;

	sf::Sprite floor;
	Wall*** walls;
	bool** map;
};