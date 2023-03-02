#include "Configure.h"



namespace Configure {
	inline void setSprite(sf::Sprite& sprite, sf::IntRect& textureRect, float width, float height) {
		sprite.setTexture(tanksTexture);
		sprite.setTextureRect(textureRect);
		sprite.setOrigin(textureRect.width / 2, textureRect.height / 2);

		float scaleW = width / textureRect.width;
		float scaleH = height / textureRect.height;
		sprite.setScale(sf::Vector2f(scaleW, scaleH));
	}

	sf::Texture tanksTexture;

	sf::Sprite tankSprite;
	sf::IntRect tankTextureRect = sf::IntRect(0, 0, 16, 16);
	
	sf::Sprite wallSprite;
	sf::IntRect wallTextureRect = sf::IntRect(96, 16, 16, 16);

	sf::Sprite bulletSprite;
	sf::IntRect bulletTextureRect = sf::IntRect(70, 53, 4, 6);

	sf::Sprite floorSprite;
	sf::IntRect floorTextureRect = sf::IntRect(144, 0, 16, 16);

	float tankWidth = 48.0f;
	int tankMaxHp = 100;
	float tankSpeed = 0.1f;

	float wallWidth = 32.0f;
	int wallMaxHp = 100;

	float bulletWidth = 10.0f;
	float bulletHeight = 15.0f;
	int bulletDamage = 100;
	int bulletLifeTime = 3000;
	float bulletSpeed = 0.2f;

	int gunReloadTime = 500;

	int mapWidth = 40;
	int mapHeight = 30;
	
	void Init(sf::VideoMode videoMode)
	{
		if (!tanksTexture.loadFromFile("assets/tanks.png")) {
			std::cout << "Couldn't load texture";
		}
		else {
			mapWidth = videoMode.width / wallWidth;
			mapHeight = videoMode.height / wallWidth;

			setSprite(tankSprite, tankTextureRect, tankWidth, tankWidth);
			setSprite(wallSprite, wallTextureRect, wallWidth, wallWidth);
			setSprite(bulletSprite, bulletTextureRect, bulletWidth, bulletHeight);
			setSprite(floorSprite, floorTextureRect, wallWidth, wallWidth);
		}
	}

	sf::Keyboard::Key playerUp = sf::Keyboard::Up;
	sf::Keyboard::Key playerRight = sf::Keyboard::Right;
	sf::Keyboard::Key playerDown = sf::Keyboard::Down;
	sf::Keyboard::Key playerLeft = sf::Keyboard::Left;
	sf::Keyboard::Key playerShoot = sf::Keyboard::Space;
}