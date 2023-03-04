#pragma once

#include "SFML/Graphics.hpp"
#include "../Managers/TimeListener.h"
#include "../Animation/Animation.h"

class Particles : public TimeListener {
public:
	Particles(int lifeTime, sf::Sprite sprite, sf::Texture& texture, sf::IntRect& frame, float width, float height, int frames, int animTime, float x = 0, float y = 0);

	void TimeListen(int deltaTime) override;

	void Draw(sf::RenderWindow& window);

	~Particles();
private:
	int lifeTime;
	sf::Sprite sprite;
	Animation animation;
	float x;
	float y;
};