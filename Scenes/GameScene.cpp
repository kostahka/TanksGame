#include "GameScene.h"

#include "../Controllers/PlayerController.h"

GameScene::GameScene()
	:restart(Configure::gameRestart)
{
}

void GameScene::ControlEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == restart) {
		Restart();
	}
}

void GameScene::ControlLoop()
{
}

void GameScene::StartOnePlayer()
{
	PlayerController* player = new PlayerController(PlayerType::FirstPlayer);
	SpawnTank(player);
	AddBots(4);
}

void GameScene::StartTwoPlayers()
{
	PlayerController* player = new PlayerController(PlayerType::FirstPlayer);
	SpawnTank(player);
	PlayerController* secondPlayer = new PlayerController(PlayerType::SecondPlayer);
	SpawnTank(secondPlayer);
	AddBots(4);
}

void GameScene::Draw(sf::RenderWindow& window, int deltaTime)
{
	Physics::CalculatePhysics(map, tanks, bullets, spawners, deltaTime);

	//Draw
	map.Draw(window);
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->Draw(window);
	}

	for (int i = 0; i < spawners.size(); i++) {
		spawners[i]->Draw(window);
	}

	for (int i = 0; i < tanks.size(); i++) {
		tanks[i]->Draw(window);
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Draw(window);
	}
	map.DrawForeGround(window);
}

void GameScene::AddBullet(Bullet* bullet)
{
	bullets.push_back(bullet);
}

void GameScene::AddTank(Tank* tank)
{
	tanks.push_back(tank);
}

void GameScene::AddController(Controller* controller)
{
	controllers.push_back(controller);
}

void GameScene::AddParticle(Particles* particle)
{
	particles.push_back(particle);
}

void GameScene::AddSpawner(Spawner* spawner)
{
	spawners.push_back(spawner);
}

void GameScene::DeleteBullet(Bullet* bullet)
{
	bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet));
}

void GameScene::DeleteTank(Tank* tank)
{
	tanks.erase(std::remove(tanks.begin(), tanks.end(), tank));

	for (int i = 0; i < controllers.size(); i++) {
		if (controllers[i]->tank == tank) {
			controllers[i]->tank = nullptr;
			SpawnTank(controllers[i]);
		}
	}
}

void GameScene::DeleteController(Controller* controller)
{
	controllers.erase(std::remove(controllers.begin(), controllers.end(), controller));
}

void GameScene::DeleteParticle(Particles* particle)
{
	particles.erase(std::remove(particles.begin(), particles.end(), particle));
}

void GameScene::DeleteSpawner(Spawner* spawner)
{
	spawners.erase(std::remove(spawners.begin(), spawners.end(), spawner));
}

void GameScene::SpawnTank(Controller* controller)
{
	Spawner* spawner = new Spawner(controller, map.getRandomPlaceToSpawn());
}

void GameScene::Restart()
{
	map.GenerateMap();
	for (int i = 0; i < spawners.size(); i++) {
		spawners[i]->Restart(map.getRandomPlaceToSpawn());
	}

	while (tanks.size() > 0) {
		tanks[0]->Destroy();
	}
	while (bullets.size() > 0) {
		bullets[0]->Destroy();
	}
}

void GameScene::AddBots(int count)
{
	AIController* ais = new AIController[count];
	for (int i = 0; i < count; i++) {
		SpawnTank(&ais[i]);
	}
}
