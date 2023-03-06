#pragma once

#include "Controller.h"
#include "../Managers/TimeListener.h"

class AIController : public Controller, public TimeListener{
public:
	AIController(Tank* tank = nullptr);

	void TimeListen(int deltaTime) override;
private:
	void generateProcessTime();

	int processTime;
};