#pragma once

#include "Scene.h"
#include <vector>
#include "../GameObjects/GameObject.h"
#include "../General/Map.h"
#include "../GameObjects/Tank.h"
#include "../GameObjects/Bullet.h"
#include "../General/Physics.h"
#include "../Controllers/Controller.h"
#include "../Particles/Particles.h"
#include "../Managers/IOListener.h"
#include "../GameObjects/Spawner.h"
#include "../General/TankType.h"

class GameScene : public Scene , public IOListener{
public:
	static Scene* getCurrentScene() {
		if (!current)
			current = new GameScene();
		return current;
	};
	
	void ControlEvent(sf::Event event) override;
	void ControlLoop() override;

	void StartOnePlayer();
	void StartTwoPlayers();
	void Draw(sf::RenderWindow& window, int deltaTime) override;

	void AddBullet(Bullet* bullet);
	void AddTank(Tank* tank);
	void AddController(Controller* controller);
	void AddParticle(Particles* particle);
	void AddSpawner(Spawner* spawner);

	void DeleteBullet(Bullet* bullet);
	void DeleteTank(Tank* tank);
	void DeleteController(Controller* controller);
	void DeleteParticle(Particles* particle);
	void DeleteSpawner(Spawner* spawner);

private:
	void SpawnTank(Controller* controller);
	void Restart();

	std::vector<Particles*> particles;
	std::vector<Controller*> controllers;
	std::vector<Tank*> tanks;
	std::vector<Bullet*> bullets;
	std::vector<Spawner*> spawners;
	Map map;

	sf::Keyboard::Key restart;
protected:
	GameScene();
};