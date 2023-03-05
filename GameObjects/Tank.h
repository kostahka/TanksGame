#pragma once

#include "DynamicObject.h"
#include "Gun.h"
#include "../Animation/Animation.h"
#include "../General/TankType.h"
#include "../GUI/HealthBar.h"

class Tank : public DynamicObject{
public:
	Tank(TankType type, float x = 0, float y = 0);

	void Draw(sf::RenderWindow& window) override;
	void setDirection(MovingDirection direction) override;
	void Move(int deltaTime) override;

	void Shoot();
	bool Hurt(int damage) override;

	void Destroy() override;
private:
	void setShootingSrite();
	sf::Sprite shooting;
	Animation shootingAnimation;
	Animation animation;
	Gun gun;

	HealthBar healthBar;
protected:
	
};