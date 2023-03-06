#include "AIController.h"

AIController::AIController(Tank* tank)
	:Controller(TankType::Enemy, tank)
{
	generateProcessTime();
}

void AIController::TimeListen(int deltaTime)
{
	TimeListener::TimeListen(deltaTime);

	if (time > processTime) {
		time = 0;
		if (tank) {
			float shootRoll = (rand() / RAND_MAX);
			if (shootRoll < 0.5)
				tank->Shoot();

			MovingDirection movingRoll = MovingDirection(rand() % 5);
			tank->setDirection(movingRoll);
			generateProcessTime();
		}
		
	}
}

void AIController::generateProcessTime()
{
	processTime = Configure::AIProcessMinTime + rand() % (Configure::AIProcessMaxTime - Configure::AIProcessMinTime);
}
