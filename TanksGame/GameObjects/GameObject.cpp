#include "GameObject.h"

GameObject::GameObject(float width, float height, int maxHp, sf::Sprite sprite, float x, float y, bool isImmortal)
	:rect(sf::FloatRect(x, y, width, height)), maxHp(maxHp), isImmortal(isImmortal)
{
	hp = maxHp;
	this->sprite = sprite;
	this->sprite.setPosition(x + width / 2, y + height / 2);
}

bool GameObject::Hurt(int damage)
{
	if (!isImmortal) {
		hp -= damage;
		if (hp <= 0) {
			Destroy();
			return true;
		}
	}
	return false;
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

int GameObject::getHp() const
{
	return hp;
}

void GameObject::Destroy()
{
	delete this;
}
