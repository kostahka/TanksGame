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

	sf::Sprite healthBarSprite;
	sf::IntRect healthBarTextureRect = sf::IntRect(96, 32, 32, 16);
	sf::Sprite healthGreenSprite;
	sf::IntRect healthGreenTextureRect = sf::IntRect(128, 32, 16, 16);
	sf::Sprite healthRedSprite;
	sf::IntRect healthRedTextureRect = sf::IntRect(144, 32, 16, 16);

	sf::IntRect spawnerSpriteRect = sf::IntRect(96, 48, 16, 16);
	int spawnerAnimationFrames = 4;
	int spawnerAnimationTime = 50;

	sf::Sprite explosionSprite;
	sf::IntRect explosionSpriteRect = sf::IntRect(0, 64, 16, 16);
	int explosionAnimationFrames = 5;
	int explosionAnimationTime = 50;
	int explosionLifeTime = explosionAnimationFrames * explosionAnimationTime;

	sf::Sprite shootingSprite;
	sf::IntRect shootingSpriteRect = sf::IntRect(0, 48, 16, 16);
	int shootingAnimationFrames = 4;
	int shootingAnimationTime = 50;

	sf::Sprite tankSprite;
	sf::IntRect tankTextureRect = sf::IntRect(0, 0, 16, 16);
	sf::IntRect secondTankTextureRect = sf::IntRect(0, 32, 16, 16);
	sf::IntRect enemyTankTextureRect = sf::IntRect(0, 16, 16, 16);
	int tankAnimationFrames = 5;
	int tankAnimationTime = 50;
	
	sf::Sprite wallSprite;
	sf::IntRect wallTextureRect = sf::IntRect(96, 16, 16, 16);
	sf::Sprite grassSprite;
	sf::IntRect grassTextureRect = sf::IntRect(96, 0, 16, 16);
	sf::Sprite immortalWallSprite;
	sf::IntRect immortalWallTextureRect = sf::IntRect(112, 16, 16, 16);
	sf::Sprite waterSprite;
	sf::IntRect waterTextureRect = sf::IntRect(112, 0, 16, 16);

	sf::Sprite bulletSprite;
	sf::IntRect bulletTextureRect = sf::IntRect(70, 53, 4, 6);

	sf::Sprite floorSprite;
	sf::IntRect floorTextureRect = sf::IntRect(144, 0, 16, 16);

	int timeToSpawn = 4000;

	float healthBarWidth = 76.0f;
	float healthBarHeight = 32.0f;

	float explosionWidth = 32.0f;

	float shootingWidth = 48.0f;

	float tankWidth = 48.0f;
	int tankMaxHp = 100;
	float tankSpeed = 0.2f;

	float wallWidth = 32.0f;
	int wallMaxHp = 25;

	float bulletWidth = 10.0f;
	float bulletHeight = 15.0f;
	int bulletDamage = 25;
	int bulletLifeTime = 1500;
	float bulletSpeed = 0.4f;

	float bulletExplosionRadius = 14.0f;

	int gunReloadTime = 300;

	int mapWidth = 50;
	int mapHeight = 30;

	float mapWallsFill = 0.5f;
	float mapImmortalWallsFill = 0.4f;
	float mapWaterFill = 0.4f;
	float mapGrassFill = 0.4f;

	int AIProcessMinTime = 100;
	int AIProcessMaxTime = 1500;
	
	void Init(sf::RenderWindow& window)
	{
		if (!tanksTexture.loadFromFile("assets/tanks.png")) {
			std::cout << "Couldn't load texture";
		}
		else {
			sf::View view = window.getView();
			view.setSize(mapWidth * wallWidth, mapHeight * wallWidth);
			view.setCenter(sf::Vector2f(mapWidth * wallWidth / 2, mapHeight * wallWidth / 2));
			window.setView(view);

			setSprite(tankSprite, tankTextureRect, tankWidth, tankWidth);
			
			setSprite(wallSprite, wallTextureRect, wallWidth, wallWidth);
			setSprite(grassSprite, grassTextureRect, wallWidth, wallWidth);
			setSprite(immortalWallSprite, immortalWallTextureRect, wallWidth, wallWidth);
			setSprite(waterSprite, waterTextureRect, wallWidth, wallWidth);

			setSprite(bulletSprite, bulletTextureRect, bulletWidth, bulletHeight);
			setSprite(floorSprite, floorTextureRect, wallWidth, wallWidth);
			setSprite(shootingSprite, shootingSpriteRect, shootingWidth, shootingWidth);
			setSprite(explosionSprite, explosionSpriteRect, explosionWidth, explosionWidth);

			setSprite(healthBarSprite, healthBarTextureRect, healthBarWidth, healthBarHeight);
			setSprite(healthRedSprite, healthRedTextureRect, healthBarWidth, healthBarHeight);
			setSprite(healthGreenSprite, healthGreenTextureRect, healthBarWidth, healthBarHeight);

			floorSprite.setColor(sf::Color(155, 155, 155));
		}
	}

	sf::Keyboard::Key playerUp = sf::Keyboard::W;
	sf::Keyboard::Key playerRight = sf::Keyboard::D;
	sf::Keyboard::Key playerDown = sf::Keyboard::S;
	sf::Keyboard::Key playerLeft = sf::Keyboard::A;
	sf::Keyboard::Key playerShoot = sf::Keyboard::Space;

	sf::Keyboard::Key playerSecondUp = sf::Keyboard::Up;
	sf::Keyboard::Key playerSecondRight = sf::Keyboard::Right;
	sf::Keyboard::Key playerSecondDown = sf::Keyboard::Down;
	sf::Keyboard::Key playerSecondLeft = sf::Keyboard::Left;
	sf::Keyboard::Key playerSecondShoot = sf::Keyboard::Numpad0;

	sf::Keyboard::Key gameRestart = sf::Keyboard::R;
}