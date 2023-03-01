#pragma once

#include "DynamicObject.h"
#include "Gun.h"

class Tank : public DynamicObject{
public:
	Tank(float x = 0, float y = 0);

	void setDirection(MovingDirection direction);
	void Shoot();
private:	
	Gun gun;
protected:
	void Destroy() override;
};