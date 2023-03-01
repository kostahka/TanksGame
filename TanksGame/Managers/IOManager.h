#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "../Controllers/PlayerController.h"

class IOManager {
public:
	static IOManager* getCurrent();

	void KeyboardEvent(sf::Event event);
	void InputLoop();

	void AddPlayerController(PlayerController* controller);
	void DeletePlayerController(PlayerController* controller);
private:
	IOManager();
	static IOManager* current;

	std::vector<PlayerController*> playerControllers;
};