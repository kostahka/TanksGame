#include "HealthBar.h"

HealthBar::HealthBar(sf::Vector2f position)
	:healthBar(Configure::healthBarSprite), healthGreen(Configure::healthGreenSprite),
	healthRed(Configure::healthRedSprite), width(Configure::healthBarWidth), height(Configure::healthBarHeight)
{
	scaleW = width / Configure::healthGreenTextureRect.width;
	scaleH = height / Configure::healthGreenTextureRect.height;

	SetPosition(position);
}

void HealthBar::Draw(sf::RenderWindow& window)
{
	window.draw(healthRed);
	window.draw(healthGreen);
	window.draw(healthBar);
}

void HealthBar::SetPercentage(float perc)
{
	percentage = perc;

	SetPosition(position);
}

void HealthBar::SetPosition(sf::Vector2f pos)
{
	position = pos;

	healthBar.setPosition(pos);
	healthGreen.setScale(sf::Vector2f(scaleW  * (percentage / 100.0f), scaleH));
	healthGreen.setPosition(sf::Vector2f(pos));
	healthRed.setPosition(pos);
}
