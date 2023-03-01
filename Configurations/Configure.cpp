#include "Configure.h"

namespace Configure {
	sf::Texture tanksTexture;
	sf::Sprite tankSprite;
	sf::Sprite wallSprite;
	sf::Sprite bulletSprite;
	sf::Sprite floorSprite;

	float tankSpriteScale = 1.5f;
	float wallSpriteScale = 1.0f;
	float bulletSpriteScale = 2.0f;
	float floorSpriteScale = 1.0f;
	
	void Init()
	{
		if (!tanksTexture.loadFromFile("assets/tanks.png")) {
			std::cout << "Couldn't load texture";
		}
		else {
			tankSprite.setTexture(tanksTexture);
			wallSprite.setTexture(tanksTexture);
			bulletSprite.setTexture(tanksTexture);
			floorSprite.setTexture(tanksTexture);

			tankSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
			wallSprite.setTextureRect(sf::IntRect(96, 16, 16, 16));
			bulletSprite.setTextureRect(sf::IntRect(70, 53, 4, 6));
			floorSprite.setTextureRect(sf::IntRect(144, 0, 16, 16));

			tankSprite.setOrigin(sf::Vector2f(8, 8));
			wallSprite.setOrigin(sf::Vector2f(8, 8));
			bulletSprite.setOrigin(sf::Vector2f(2, 3));
			floorSprite.setOrigin(sf::Vector2f(8, 8));

			tankSprite.setScale(sf::Vector2f(tankSpriteScale, tankSpriteScale));
			wallSprite.setScale(sf::Vector2f(wallSpriteScale, wallSpriteScale));
			bulletSprite.setScale(sf::Vector2f(bulletSpriteScale, bulletSpriteScale));
			floorSprite.setScale(sf::Vector2f(floorSpriteScale, floorSpriteScale));
		}
	}

	sf::Keyboard::Key playerUp = sf::Keyboard::Up;
	sf::Keyboard::Key playerRight = sf::Keyboard::Right;
	sf::Keyboard::Key playerDown = sf::Keyboard::Down;
	sf::Keyboard::Key playerLeft = sf::Keyboard::Left;
	sf::Keyboard::Key playerShoot = sf::Keyboard::Space;

	float tankWidth = 24.0f;
	int tankMaxHp = 100;
	float tankSpeed = 0.1f;

	float wallWidth = 16.0f;
	int wallMaxHp = 100;

	float bulletWidth = 12.0f;
	float bulletHeight = 8.0f;
	int bulletDamage = 100;
	int bulletLifeTime = 10000;
	float bulletSpeed = 0.2f;

	int mapWidth = 40;
	int mapHeight = 30;
}