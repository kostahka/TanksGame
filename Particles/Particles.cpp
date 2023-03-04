#include "Particles.h"

#include "../Scenes/GameScene.h"

Particles::Particles(int lifeTime, sf::Sprite sprite, sf::Texture& texture, sf::IntRect& frame, float width, float height, int frames, int animTime, float x, float y)
	:lifeTime(lifeTime), sprite(sprite), animation(Animation(texture, frame, width, height, frames, animTime)), x(x), y(y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
	animation.PlayOneShot();
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->AddParticle(this);
	}
}

void Particles::TimeListen(int deltaTime)
{
	TimeListener::TimeListen(deltaTime);
	if (time > lifeTime)
		delete this;
}

void Particles::Draw(sf::RenderWindow& window)
{
	animation.Draw(window, sprite);
}

Particles::~Particles()
{
	GameScene* scene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
	if (scene) {
		scene->DeleteParticle(this);
	}
}
