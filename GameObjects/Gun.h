#pragma once

#include "../Configurations/Configure.h"
#include "../General/Direction.h"
#include "Bullet.h"
#include "../Managers/TimeListener.h"

class Gun : public TimeListener{
public:
	Gun();

	void TimeListen(int deltaTime) override;
	bool canShoot();
	void Shoot(Direction direction, float x, float y);
private:
	float bulletSpeed;
	int bulletDamage;
	int bulletLifeTime;
	int reloadTime;
};