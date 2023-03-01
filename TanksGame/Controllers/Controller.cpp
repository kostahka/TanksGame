#include "Controller.h"

#include "../Scenes/GameScene.h"

Controller::Controller(Tank* tank)
	:tank(tank)
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
