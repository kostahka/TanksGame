#include "IOListener.h"

#include "IOManager.h"

IOListener::IOListener()
{
	IOManager* manager = IOManager::getCurrent();
	manager->AddListener(this);
}

IOListener::~IOListener()
{
	IOManager* manager = IOManager::getCurrent();
	manager->DeleteListener(this);
}
