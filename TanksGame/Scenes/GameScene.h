#pragma once

#include "Scene.h"
#include <vector>
#include "../GameObjects/GameObject.h"
#include "../General/Map.h"
#include "../GameObjects/Tank.h"
#include "../GameObjects/Bullet.h"
#include "../General/Physics.h"
#include "../Controllers/Controller.h"

class GameScene : public Scene {
public:
	static Scene* getCurrentScene() {
		if (!current)
			current = new GameScene();
		return current;
	};
	

	void StartOnePlayer();
	void Draw(sf::RenderWindow& window, int deltaTime) override;

	void AddBullet(Bullet* bullet);
	void AddTank(Tank* tank);
	void AddController(Controller* controller);

	void DeleteBullet(Bullet* bullet);
	void DeleteTank(Tank* tank);
	void DeleteController(Controller* controller);
private:
	std::vector<Controller*> controllers;
	std::vector<Tank*> tanks;
	std::vector<Bullet*> bullets;
	Map map;
protected:
	GameScene();
};