#pragma once

#include "../GameObjects/Tank.h"

class Controller {
public:
	Controller(Tank *tank);
	~Controller();

	virtual void Destroy();

	Tank *tank;
};