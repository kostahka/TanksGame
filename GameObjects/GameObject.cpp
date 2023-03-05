#include "GameObject.h"

GameObject::GameObject(float width, float height, int maxHp, sf::Sprite sprite, float x, float y, bool isImmortal)
	:rect(sf::FloatRect(x, y, width, height)), maxHp(maxHp), isImmortal(isImmortal)
{
	hp = maxHp;
	SetSprite(sprite);
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

void GameObject::SetSprite(sf::Sprite sprite)
{
	this->sprite = sprite;
	this->sprite.setPosition(rect.left + rect.width / 2, rect.top + rect.height / 2);
}

void GameObject::Destroy()
{
	delete this;
}
