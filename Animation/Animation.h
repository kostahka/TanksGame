#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "../Managers/TimeListener.h"

class Animation : public TimeListener{
public:
	Animation(sf::Texture& texture, sf::IntRect& frame, float width, float height, int frames, int animTime);

	void TimeListen(int deltaTime) override;

	void Draw(sf::RenderWindow& window, sf::Sprite& drawSprite);

	void Pause();
	void Play();
	void Replay();
	void Hide();
	void PlayOneShot();

	void SetTextureRect(sf::IntRect& frame, float width, float height);
	void SetColor(sf::Color color);
private:
	sf::Texture* texture;
	sf::IntRect frame;
	std::vector<sf::Sprite> sprites;
	int animTime;
	int frames;
	int currentFrame;
	bool isHiding;
	bool isOneShot;
	bool isPlaying;
};