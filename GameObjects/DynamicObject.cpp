#include "DynamicObject.h"

DynamicObject::DynamicObject(Direction direction, float speed, float width, float height, int maxHp, sf::Sprite sprite, float x, float y, bool isImmortal)
	:GameObject(width, height, maxHp, sprite, x, y, isImmortal), direction(direction), speed(speed), isMoving(false)
{
	startRect = sf::FloatRect(x, y, width, height);

	setRotation(direction);
}

void DynamicObject::Move(int deltaTime)
{
	float delta = deltaTime * speed;
	switch (direction)
	{
	case Direction::Down:
		rect.top += delta;
		break;
	case Direction::Up:
		rect.top -= delta;
		break;
	case Direction::Left:
		rect.left -= delta;
		break;
	case Direction::Right:
		rect.left += delta;
		break;
	default:
		break;
	}

	sprite.setPosition(rect.left + rect.width / 2, rect.top + rect.height / 2);
}

void DynamicObject::setDirection(MovingDirection direction)
{
	if (direction != MovingDirection::None) {
		this->direction = Direction((int)direction);
		setRotation(this->direction);
		isMoving = true;
	}
	else {
		isMoving = false;
	}
}

sf::FloatRect DynamicObject::getMoved(int deltaTime) const
{
	sf::FloatRect newRect = rect;
	
	float delta = deltaTime * speed;
	switch (direction)
	{
	case Direction::Down:
		newRect.top += delta;
		break;
	case Direction::Up:
		newRect.top -= delta;
		break;
	case Direction::Left:
		newRect.left -= delta;
		break;
	case Direction::Right:
		newRect.left += delta;
		break;
	default:
		break;
	}

	return newRect;
}

bool DynamicObject::getMoving() const
{
	return isMoving;
}

void DynamicObject::setRotation(Direction direction)
{
	if (!(direction == Direction::Up || direction == Direction::Down))
	{
		rect.width = startRect.height;
		rect.height = startRect.width;
	}
	else {
		rect.width = startRect.width;
		rect.height = startRect.height;
	}
	switch (direction)
	{
	case Direction::Down:
		sprite.setRotation(180.0f);
		break;
	case Direction::Up:
		sprite.setRotation(0.0f);
		break;
	case Direction::Left:
		sprite.setRotation(-90.0f);
		break;
	case Direction::Right:
		sprite.setRotation(90.0f);
		break;
	default:
		break;
	}
}
