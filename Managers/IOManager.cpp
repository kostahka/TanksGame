#include "IOManager.h"

IOManager* IOManager::current = nullptr;

IOManager* IOManager::getCurrent()
{
	if (!current) {
		current = new IOManager();
	}
	return current;
}

void IOManager::KeyboardEvent(sf::Event event)
{
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i]->ControlEvent(event);
	}
}

void IOManager::InputLoop()
{
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i]->ControlLoop();
	}
}

void IOManager::AddListener(IOListener* listener)
{
	listeners.push_back(listener);
}

void IOManager::DeleteListener(IOListener* listener)
{
	listeners.erase(std::remove(listeners.begin(), listeners.end(), listener));
}

IOManager::IOManager() {

}
