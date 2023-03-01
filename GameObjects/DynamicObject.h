#pragma once

#include "GameObject.h"
#include "../General/Direction.h"

class DynamicObject : public GameObject {
public:
	DynamicObject(Direction direction, float speed, float width, float height, int maxHp, sf::Sprite sprite, float x = 0, float y = 0, bool isImmortal = false);

	void Move(int deltaTime);
	sf::FloatRect getMoved(int deltaTime) const;
	bool getMoving() const;
private:
	sf::FloatRect startRect;
	void setRotation(Direction direction);
protected:
	Direction direction;
	bool isMoving;
	float speed;
};