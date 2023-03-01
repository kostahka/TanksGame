#pragma once

#include "../Configurations/Configure.h"
#include "../General/Direction.h"
#include "Bullet.h"

class Gun {
public:
	Gun();

	void Shoot(Direction direction, float x, float y);
private:
	float bulletSpeed;
	int bulletDamage;
	int bulletLifeTime;
};