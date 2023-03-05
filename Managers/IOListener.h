#pragma once

#include "SFML/Graphics.hpp"

class IOListener {
public:
	IOListener();
	~IOListener();

	virtual void ControlEvent(sf::Event event) = 0;
	virtual void ControlLoop() = 0;
};