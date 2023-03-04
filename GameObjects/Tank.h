#pragma once

#include "DynamicObject.h"
#include "Gun.h"
#include "../Animation/Animation.h"

class Tank : public DynamicObject{
public:
	Tank(float x = 0, float y = 0);

	void Draw(sf::RenderWindow& window) override;
	void setDirection(MovingDirection direction) override;
	void Move(int deltaTime) override;

	void Shoot();
private:
	void setShootingSrite();
	sf::Sprite shooting;
	Animation shootingAnimation;
	Animation animation;
	Gun gun;
protected:
	void Destroy() override;
};