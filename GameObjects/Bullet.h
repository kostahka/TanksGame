#pragma once

#include "DynamicObject.h"

class Bullet : public DynamicObject {
public:
	Bullet(Direction direction, float speed, int damage, int lifeTime, float x = 0, float y = 0);

	bool Hurt(int damage = 0) override;
private:
	int lifeTime;
protected:
	void Destroy() override;
};