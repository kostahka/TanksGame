#pragma once

#include "../GameObjects/Tank.h"
#include "Controller.h"
#include "SFML/System.hpp"
#include "../Managers/IOListener.h"

enum class PlayerType {
	FirstPlayer, SecondPlayer
};

class PlayerController : public Controller, public IOListener{
public:
	PlayerController(PlayerType type, Tank* tank = nullptr);

	void ControlEvent(sf::Event event) override;
	void ControlLoop() override;
private:

	sf::Keyboard::Key up;
	sf::Keyboard::Key right;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key shoot;
};