#pragma once

class TimeListener {
public:
	virtual void TimeListen(int deltaTime);
	TimeListener();
	~TimeListener();
protected:
	int time;
};