#pragma once

#include "../GameObjects/Bullet.h"
#include "../Controllers/Controller.h"
#include "Map.h"
#include <vector>
#include "SFML/Graphics.hpp"

namespace Physics {
	void CalculatePhysics(Map& map, std::vector<Tank*>& tanks, std::vector<Bullet*>& bullets, int deltaTime);
};