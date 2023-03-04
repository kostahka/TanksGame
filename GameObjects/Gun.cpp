#include "Gun.h"

Gun::Gun()
	:bulletDamage(Configure::bulletDamage), bulletLifeTime(Configure::bulletLifeTime), bulletSpeed(Configure::bulletSpeed),
	reloadTime(Configure::gunReloadTime)
{
	
}

void Gun::TimeListen(int deltaTime)
{
	TimeListener::TimeListen(deltaTime);
}

bool Gun::canShoot()
{
	return time > reloadTime;
}

void Gun::Shoot(Direction direction, float x, float y)
{	
	time = 0;

	float correctX = x;
	float correctY = y;
	switch (direction)
	{
	case Direction::Up:
		correctY -= Configure::bulletHeight;
		correctX -= Configure::bulletWidth / 2;
		break;
	case Direction::Right:
		correctY -= Configure::bulletWidth / 2;
		break;
	case Direction::Down:
		correctX -= Configure::bulletWidth / 2;
		break;
	case Direction::Left:
		correctY -= Configure::bulletWidth / 2;
		correctX -= Configure::bulletHeight;
		break;
	default:
		break;
	}
	Bullet* bullet = new Bullet(direction, bulletSpeed, bulletDamage, bulletLifeTime, correctX, correctY);
}
