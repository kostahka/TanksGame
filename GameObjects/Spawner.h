#pragma once

#include "GameObject.h"
#include "../Managers/TimeListener.h"
#include "../Controllers/Controller.h"
#include "../General/Map.h"
#include "../Configurations/Configure.h"

class Spawner :  public GameObject, public TimeListener{
public:
	Spawner(Controller* controller, sf::Vector2f position);
	~Spawner();

	void TimeListen(int deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	void Restart(sf::Vector2f position);
private:
	Controller* controller;
	int timeToSpawn;

	Animation animation;
};