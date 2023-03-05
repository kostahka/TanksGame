#include "Tank.h"

#include "../Scenes/GameScene.h"

Tank::Tank(TankType type, float x, float y)
	:DynamicObject(Direction::Up, Configure::tankSpeed, Configure::tankWidth, Configure::tankWidth, Configure::tankMaxHp,
		Configure::tankSprite, x, y), 
		animation(Animation(Configure::tanksTexture, Configure::tankTextureRect,
			Configure::tankWidth, Configure::tankWidth,
			Configure::tankAnimationFrames, Configure::tankAnimationTime)),
		shooting(Configure::shootingSprite),
		shootingAnimation(Animation(Configure::tanksTexture, Configure::shootingSpriteRect, Configure::shootingWidth,
			Configure::shootingWidth, Configure::shootingAnimationFrames, Configure::shootingAnimationTime))
{
	sf::IntRect textureRect;
	switch (type)
	{
	case TankType::First:
		textureRect = Configure::tankTextureRect;
		break;
	case TankType::Second:
		textureRect = Configure::secondTankTextureRect;
		break;
	case TankType::Enemy:
		textureRect = Configure::enemyTankTextureRect;
		break;
	default:
		break;
	}
	animation.SetTextureRect(textureRect, rect.width, rect.height);

	shootingAnimation.Hide();
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->AddTank(this);
	}
	setShootingSrite();
}

void Tank::Draw(sf::RenderWindow& window)
{
	//GameObject::Draw(window);
	animation.Draw(window, sprite);
	shootingAnimation.Draw(window, shooting);
}

void Tank::Shoot()
{
	if (gun.canShoot()) {
		shootingAnimation.PlayOneShot();
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
}

void Tank::setShootingSrite()
{
	switch (direction)
	{
	case Direction::Down:
		shooting.setRotation(180.0f);
		shooting.setPosition(sf::Vector2f(rect.left + 0.5f * rect.width, rect.top + 1.5 * rect.height));
		break;
	case Direction::Up:
		shooting.setRotation(0.0f);
		shooting.setPosition(sf::Vector2f(rect.left + 0.5f * rect.width, rect.top - 0.5 * rect.height));
		break;
	case Direction::Left:
		shooting.setRotation(-90.0f);
		shooting.setPosition(sf::Vector2f(rect.left - 0.5f * rect.width, rect.top + 0.5 * rect.height));
		break;
	case Direction::Right:
		shooting.setRotation(90.0f);
		shooting.setPosition(sf::Vector2f(rect.left + 1.5f * rect.width, rect.top + 0.5 * rect.height));
		break;
	default:
		break;
	}
}

void Tank::Destroy()
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->DeleteTank(this);
	}
	delete this;
}

void Tank::setDirection(MovingDirection direction)
{
	DynamicObject::setDirection(direction);
	if (direction == MovingDirection::None)
		animation.Pause();
	else
		animation.Play();
	setShootingSrite();
}

void Tank::Move(int deltaTime)
{
	DynamicObject::Move(deltaTime);
}
