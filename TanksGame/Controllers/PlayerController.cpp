#include "PlayerController.h"

#include "../Managers/IOManager.h"

PlayerController::PlayerController(Tank* tank)
	:Controller(tank)
{
	up = Configure::playerUp;
	right = Configure::playerRight;
	down = Configure::playerDown;
	left = Configure::playerLeft;
	shoot = Configure::playerShoot;

	IOManager* manager = dynamic_cast<IOManager*>(IOManager::getCurrent());
	if (manager) {
		manager->AddPlayerController(this);
	}
}

void PlayerController::Destroy()
{
	IOManager* manager = dynamic_cast<IOManager*>(IOManager::getCurrent());
	if (manager) {
		manager->DeletePlayerController(this);
	}
	Controller::Destroy();
}

void PlayerController::ControlEvent(sf::Event event)
{
	if (tank) {
		if (event.type == sf::Event::KeyPressed) {
			if(event.key.code == shoot)
				tank->Shoot();
		}
	}
	
}

void PlayerController::ControlLoop()
{
	if (sf::Keyboard::isKeyPressed(up)) {
		tank->setDirection(MovingDirection::Up);
	}
	else if (sf::Keyboard::isKeyPressed(right)) {
		tank->setDirection(MovingDirection::Right);
	}
	else if (sf::Keyboard::isKeyPressed(down)) {
		tank->setDirection(MovingDirection::Down);
	}
	else if (sf::Keyboard::isKeyPressed(left)) {
		tank->setDirection(MovingDirection::Left);
	}
	else {
		tank->setDirection(MovingDirection::None);
	}
}

