#include "Tank.h"

#include "../Scenes/GameScene.h"

Tank::Tank(float x, float y)
	:DynamicObject(Direction::Up, Configure::tankSpeed, Configure::tankWidth, Configure::tankWidth, Configure::tankMaxHp,
		Configure::tankSprite, x, y)
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->AddTank(this);
	}
}

void Tank::setDirection(MovingDirection direction)
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

void Tank::Shoot()
{
	float x = rect.left;
	float y = rect.top;
	switch (direction)
	{
	case Direction::Up:
		x += rect.width / 2;
		break;
	case Direction::Right:
		x += rect.width;
		y += rect.height / 2;
		break;
	case Direction::Down:
		x += rect.width / 2;
		y += rect.height;
		break;
	case Direction::Left:
		y += rect.height / 2;
		break;
	default:
		break;
	}
	gun.Shoot(direction, x, y);
}

void Tank::Destroy()
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->DeleteTank(this);
	}
	GameObject::Destroy();
}
