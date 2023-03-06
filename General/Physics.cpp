#include "Physics.h"

#include <math.h>

namespace Physics {
	bool GameObjectMapCollision(sf::FloatRect A, Map & map, bool isTank) {
		int left = floor(A.left / Configure::wallWidth);
		int top = floor(A.top / Configure::wallWidth);
		int width = ceil((A.left + A.width) / Configure::wallWidth) - left;
		int height = ceil((A.top + A.height) / Configure::wallWidth) - top;

		if (left < 0 || top < 0 ||
			left + width > map.getWidth() || top + height > map.getHeight())
		{
			return true;
		}

		for (int i = top >= 0 ? top : 0; (i < top + height) && (i < map.getHeight()); i++) {
			for (int j = left >= 0 ? left : 0; (j < left + width) && (j < map.getWidth()); j++) {
				if (map[i][j])
					return true;
			}
		}

		if (isTank) {
			for (int i = top >= 0 ? top : 0; (i < top + height) && (i < map.getHeight()); i++) {
				for (int j = left >= 0 ? left : 0; (j < left + width) && (j < map.getWidth()); j++) {
					if (map.getSea(i, j))
						return true;
				}
			}
		}

		return false;
	}

	bool GameObjectsCollision(sf::FloatRect A, sf::FloatRect B) {
		return !((A.left + A.width < B.left)
			|| (A.left > B.left + B.width)
			|| (A.top + A.height < B.top)
			|| (A.top > B.top + B.height));
	}
}

void Physics::CalculatePhysics(Map& map, std::vector<Tank*>& tanks, std::vector<Bullet*>& bullets, std::vector<Spawner*> spawners,
	int deltaTime)
{
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i]->getMoving()) {
			bool move = true;

			sf::FloatRect newRect = tanks[i]->getMoved(deltaTime);
			if (!GameObjectMapCollision(newRect, map, true)) {
				for (int j = 0; j < tanks.size(); j++) {
					if (i != j)
						if (GameObjectsCollision(newRect, tanks[j]->rect)) {
							move = false;
							break;
						}
				}
				if (move) {
					for (int j = 0; j < spawners.size(); j++) {
						if (GameObjectsCollision(newRect, spawners[j]->rect)) {
							move = false;
							break;
						}
					}
				}
				if (move)
					tanks[i]->Move(deltaTime);
			}
		}
	}
	int i = 0;
	while (i < bullets.size()) {
		bullets[i]->Move(deltaTime);

		if (GameObjectMapCollision(bullets[i]->rect, map, false)) {
			map.Hurt(bullets[i]->getHp(), bullets[i]->rect.left + bullets[i]->rect.width / 2,
				bullets[i]->rect.top + bullets[i]->rect.height / 2);

			bullets[i]->Hurt();
			continue;
		}

		bool collision = false;
		for (int j = 0; j < tanks.size(); j++) {
			if (GameObjectsCollision(bullets[i]->rect, tanks[j]->rect)) {
				tanks[j]->Hurt(bullets[i]->getHp());

				bullets[i]->Hurt();
				collision = true;
				break;
			}
		}
		if (collision)
			continue;

		for (int j = 0; j < spawners.size(); j++) {
			if (GameObjectsCollision(bullets[i]->rect, spawners[j]->rect)) {
				bullets[i]->Hurt();
				collision = true;
				break;
			}
		}
		if (collision)
			continue;
		i++;
	}
}