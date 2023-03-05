#pragma once

#include "SFML/Graphics.hpp"
#include "../Configurations/Configure.h"

class HealthBar {
public:
	HealthBar(sf::Vector2f position);

	void Draw(sf::RenderWindow& window);
	void SetPercentage(float perc);
	void SetPosition(sf::Vector2f pos);
private:
	sf::Vector2f position;
	float percentage = 100.0;
	sf::Sprite healthBar;
	sf::Sprite healthGreen;
	sf::Sprite healthRed;
	float width;
	float height;
	float scaleW;
	float scaleH;
};