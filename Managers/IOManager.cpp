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
	for (int i = 0; i < playerControllers.size(); i++)
	{
		playerControllers[i]->ControlEvent(event);
	}
}

void IOManager::InputLoop()
{
	for (int i = 0; i < playerControllers.size(); i++)
	{
		playerControllers[i]->ControlLoop();
	}
}

void IOManager::AddPlayerController(PlayerController* controller)
{
	playerControllers.push_back(controller);
}

void IOManager::DeletePlayerController(PlayerController* controller)
{
	playerControllers.erase(std::remove(playerControllers.begin(), playerControllers.end(), controller));
}

IOManager::IOManager() {

}
