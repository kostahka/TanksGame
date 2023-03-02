#include "TimeListener.h"
#include "TimeListener.h"

#include "TimeManager.h"

void TimeListener::TimeListen(int deltaTime)
{
	time += deltaTime;
}

TimeListener::TimeListener()
	:time(0)
{
	TimeManager* timeManager = TimeManager::getCurrent();
	if (timeManager) {
		timeManager->AddListener(this);
	}
}

TimeListener::~TimeListener()
{
	TimeManager* timeManager = TimeManager::getCurrent();
	if (timeManager) {
		timeManager->DeleteListener(this);
	}
}
