#include "Bullet.h"

#include "../Scenes/GameScene.h"
#include "../Particles/Explosion.h"

Bullet::Bullet(Direction direction, float speed, int damage, int lifeTime, float x, float y)
	:DynamicObject(direction, speed, Configure::bulletWidth, Configure::bulletHeight, damage,
		Configure::bulletSprite, x, y)
	, lifeTime(lifeTime)
{
	isMoving = true;
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->AddBullet(this);
	}
}

void Bullet::TimeListen(int deltaTime)
{
	TimeListener::TimeListen(deltaTime);

	if (time > lifeTime)
		Destroy();
}

bool Bullet::Hurt(int damage)
{
	Destroy();
	return true;
}

void Bullet::Destroy()
{
	Explosion* explosion = new Explosion(sprite.getPosition().x, sprite.getPosition().y);
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->DeleteBullet(this);
	}
	delete this;
}
