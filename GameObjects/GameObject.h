#pragma once

#include "../Configurations/Configure.h"
#include "SFML/Graphics.hpp"

class GameObject {
public:
	GameObject(float width, float height, int maxHp, sf::Sprite sprite, float x = 0, float y = 0, bool isImmortal = false);
	
	virtual bool Hurt(int damage = 0);
	virtual void Draw(sf::RenderWindow& window);

	sf::FloatRect rect;
	
	int getHp() const;
private:
	

	int hp;
	int maxHp;

	bool isImmortal;
protected:
	sf::Sprite sprite;
	virtual void Destroy();
};