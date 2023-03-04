#pragma once

#include "GameObject.h"
#include "../General/Direction.h"

class DynamicObject : public GameObject {
public:
	DynamicObject(Direction direction, float speed, float width, float height, int maxHp, sf::Sprite sprite, float x = 0, float y = 0, bool isImmortal = false);

	virtual void Move(int deltaTime);
	sf::FloatRect getMoved(int deltaTime) const;
	bool getMoving() const;

	virtual void setDirection(MovingDirection direction);

private:
	sf::FloatRect startRect;
	
protected:
	void setRotation(Direction direction);
	Direction direction;
	bool isMoving;
	float speed;
};