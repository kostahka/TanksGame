#include "Animation.h"

Animation::Animation(sf::Texture& texture, sf::IntRect& frame, float width, float height, int frames, int animTime)
	:texture(&texture), frame(frame), frames(frames), animTime(animTime)
{
	isHiding = false;
	isOneShot = false;
	isPlaying = false;
	currentFrame = 0;
	float scaleW = width / frame.width;
	float scaleH = height / frame.height;
	for (int i = 0; i < frames; i++) {
		sf::IntRect frameRect = sf::IntRect(frame.left + i * frame.width, frame.top, frame.width, frame.height);
		sprites.push_back(sf::Sprite(texture, frameRect));
		sprites[i].setOrigin(frame.width / 2, frame.height / 2);
		sprites[i].setScale(scaleW, scaleH);
	}
}

void Animation::TimeListen(int deltaTime)
{
	if (isPlaying) {
		time += deltaTime;
		if (time > animTime)
		{
			if (isOneShot && currentFrame == frames - 1) {
				isHiding = true;
				isPlaying = false;
				isOneShot = false;
			}
			time -= animTime;
			currentFrame = (currentFrame + 1) % frames;
		}
	}
}

void Animation::Draw(sf::RenderWindow& window, sf::Sprite& drawSprite)
{
	if (!isHiding) {
		sprites[currentFrame].setPosition(drawSprite.getPosition());
		sprites[currentFrame].setRotation(drawSprite.getRotation());
		window.draw(sprites[currentFrame]);
	}
}

void Animation::Pause()
{
	isPlaying = false;
}

void Animation::Play()
{
	isPlaying = true;
	isHiding = false;
}

void Animation::Replay()
{
	time = 0;
	isPlaying = true;
	isHiding = false;
}

void Animation::Hide()
{
	isPlaying = false;
	isHiding = true;
}

void Animation::PlayOneShot()
{
	isPlaying = true;
	isHiding = false;
	isOneShot = true;
}
