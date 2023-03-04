#include "PlayerController.h"

#include "../Managers/IOManager.h"

PlayerController::PlayerController(Tank* tank, PlayerType type)
	:Controller(tank)
{
	if (type == PlayerType::FirstPlayer) {
		up = Configure::playerUp;
		right = Configure::playerRight;
		down = Configure::playerDown;
		left = Configure::playerLeft;
		shoot = Configure::playerShoot;
	}
	else {
		up = Configure::playerSecondUp;
		right = Configure::playerSecondRight;
		down = Configure::playerSecondDown;
		left = Configure::playerSecondLeft;
		shoot = Configure::playerSecondShoot;
	}
	

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
	if (tank) {
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
}

