#include "GameScene.h"

#include "../Controllers/PlayerController.h"

GameScene::GameScene()
{
}

void GameScene::StartOnePlayer()
{
	Tank* tank = new Tank(50, 50);
	PlayerController* player = new PlayerController(tank);
}

void GameScene::Draw(sf::RenderWindow& window, int deltaTime)
{
	Physics::CalculatePhysics(map, tanks, bullets, deltaTime);

	//Draw
	map.Draw(window);
	for (int i = 0; i < tanks.size(); i++) {
		tanks[i]->Draw(window);
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Draw(window);
	}
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
		}
	}
}

void GameScene::DeleteController(Controller* controller)
{
	controllers.erase(std::remove(controllers.begin(), controllers.end(), controller));
}
