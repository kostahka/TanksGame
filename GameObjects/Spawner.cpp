#include "Spawner.h"

#include "../Scenes/GameScene.h"

Spawner::Spawner(Controller* controller, sf::Vector2f position)
	:GameObject(Configure::tankWidth, Configure::tankWidth, Configure::tankMaxHp,
		Configure::tankSprite, position.x, position.y, true), controller(controller),
	timeToSpawn(Configure::timeToSpawn),
	animation(Animation(Configure::tanksTexture, Configure::spawnerSpriteRect, Configure::tankWidth, Configure::tankWidth,
		Configure::spawnerAnimationFrames, Configure::spawnerAnimationTime))
{
	animation.Play();
	switch (controller->type)
	{
	case TankType::First:
		animation.SetColor(sf::Color(0, 155, 0));
		break;
	case TankType::Second:
		animation.SetColor(sf::Color(0, 0, 255));
		break;
	case TankType::Enemy:
		animation.SetColor(sf::Color(255, 0, 0));
		break;
	default:
		break;
	}
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->AddSpawner(this);
	}
}

Spawner::~Spawner()
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->DeleteSpawner(this);
	}
}

void Spawner::TimeListen(int deltaTime)
{
	TimeListener::TimeListen(deltaTime);
	if (time > timeToSpawn)
	{
		Tank* tank = new Tank(controller->type, rect.left, rect.top);
		controller->tank = tank;
		delete this;
	}
}

void Spawner::Draw(sf::RenderWindow& window)
{
	animation.Draw(window, sprite);
}

void Spawner::Restart(sf::Vector2f position)
{
	rect.left = position.x;
	rect.top = position.y;
	sprite.setPosition(rect.left + rect.width / 2, rect.top + rect.height / 2);
	time = 0;
}
