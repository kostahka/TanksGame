#pragma once

#include "../GameObjects/Tank.h"

class Controller {
public:
	Controller(TankType type, Tank* tank = nullptr);
	~Controller();

	virtual void Destroy();

	Tank *tank;
	TankType type;
};