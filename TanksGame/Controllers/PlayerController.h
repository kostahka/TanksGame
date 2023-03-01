#pragma once

#include "../GameObjects/Tank.h"
#include "Controller.h"
#include "SFML/System.hpp"

class PlayerController : Controller{
public:
	PlayerController(Tank* tank);

	void Destroy() override;

	void ControlEvent(sf::Event event);
	void ControlLoop();
private:

	sf::Keyboard::Key up;
	sf::Keyboard::Key right;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key shoot;
};