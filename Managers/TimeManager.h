#pragma once

#include "SFML/Graphics.hpp"
#include "TimeListener.h"

class TimeManager {
public:
	static TimeManager* getCurrent();

	void TimeListen(int deltaTime);

	void AddListener(TimeListener* listener);
	void DeleteListener(TimeListener* listener);
private:
	TimeManager();
	static TimeManager* current;

	std::vector<TimeListener*> listeners;
};