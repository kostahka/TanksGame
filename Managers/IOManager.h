#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "IOListener.h"
#include "../Controllers/PlayerController.h"

class IOManager {
public:
	static IOManager* getCurrent();

	void KeyboardEvent(sf::Event event);
	void InputLoop();

	void AddListener(IOListener* listener);
	void DeleteListener(IOListener* listener);
private:
	IOManager();
	static IOManager* current;

	std::vector<IOListener*> listeners;
};