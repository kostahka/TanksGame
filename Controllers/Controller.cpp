#include "Controller.h"

#include "../Scenes/GameScene.h"

Controller::Controller(TankType type, Tank* tank)
	:tank(tank), type(type)
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->AddController(this);
	}
}

Controller::~Controller()
{
	delete tank;
}

void Controller::Destroy()
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->DeleteController(this);
	}
	delete this;
}
