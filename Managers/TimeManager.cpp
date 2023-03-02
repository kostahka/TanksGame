#include "TimeManager.h"

TimeManager* TimeManager::current = nullptr;

TimeManager::TimeManager() {

}

TimeManager* TimeManager::getCurrent()
{
	if (!current) {
		current = new TimeManager();
	}
	return current;
}

void TimeManager::TimeListen(int deltaTime)
{
	for (int i = 0; i < listeners.size(); i++) {
		listeners[i]->TimeListen(deltaTime);
	}
}

void TimeManager::AddListener(TimeListener* listener)
{
	listeners.push_back(listener);
}

void TimeManager::DeleteListener(TimeListener* listener)
{
	listeners.erase(std::remove(listeners.begin(), listeners.end(), listener));
}
