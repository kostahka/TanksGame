#pragma once

#include "../Managers/TimeListener.h"
#include "DynamicObject.h"

class Bullet : public DynamicObject, public TimeListener {
public:
	Bullet(Direction direction, float speed, int damage, int lifeTime, float x = 0, float y = 0);

	void TimeListen(int deltaTime) override;

	bool Hurt(int damage = 0) override;

	void Destroy() override;
private:
	int lifeTime;
protected:
	
};