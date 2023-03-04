#include "Physics.h"

#include <math.h>

namespace Physics {
	MapElement GameObjectMapCollision(sf::FloatRect A, Map & map) {
		int left = floor(A.left / Configure::wallWidth);
		int top = floor(A.top / Configure::wallWidth);
		int width = ceil((A.left + A.width) / Configure::wallWidth) - left;
		int height = ceil((A.top + A.height) / Configure::wallWidth) - top;

		if (left < 0 || top < 0 ||
			left + width > map.getWidth() || top + height > map.getHeight())
		{
			return MapElement{-1, -1, true};
		}

		for (int i = top >= 0 ? top : 0; (i < top + height) && (i < map.getHeight()); i++) {
			for (int j = left >= 0 ? left : 0; (j < left + width) && (j < map.getWidth()); j++) {
				if (map[i][j])
					return MapElement{i, j, true};
			}
		}

		return MapElement{-1, -1, false};
	}

	bool GameObjectsCollision(sf::FloatRect A, sf::FloatRect B) {
		return !((A.left + A.width < B.left)
			|| (A.left > B.left + B.width)
			|| (A.top + A.height < B.top)
			|| (A.top > B.top + B.height));
	}
}

void Physics::CalculatePhysics(Map& map, std::vector<Tank*>& tanks, std::vector<Bullet*>& bullets, int deltaTime)
{
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i]->getMoving()) {
			bool move = true;

			sf::FloatRect newRect = tanks[i]->getMoved(deltaTime);
			MapElement element = GameObjectMapCollision(newRect, map);
			for (int j = 0; j < tanks.size(); j++) {
				if(i != j)
				if (GameObjectsCollision(newRect, tanks[j]->rect)) {
					move = false;
					break;
				}
			}
			if(move && !element.collide)
				tanks[i]->Move(deltaTime);
		}
	}
	int i = 0;
	while (i < bullets.size()) {
		bullets[i]->Move(deltaTime);

		MapElement element = GameObjectMapCollision(bullets[i]->rect, map);
		if (element.collide) {
			if(element.column != -1)
				map.Hurt(bullets[i]->getHp(), element.row, element.column);

			bullets[i]->Hurt();
			continue;
		}

		auto tankIt = tanks.begin();
		while (tankIt != tanks.end()) {
			if (GameObjectsCollision(bullets[i]->rect, (*tankIt)->rect)) {
				(*tankIt)->Hurt(bullets[i]->getHp());

				bullets[i]->Hurt();
				i--;
				break;
			}
			tankIt++;
		}
		i++;
	}
}