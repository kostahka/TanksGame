#pragma once
#include "GameObject.h"
#include "../General/WallType.h"

class Wall : public GameObject {
public:
	Wall(WallType type, float x = 0, float y = 0);

	WallType getType() const;
private:
	WallType type;
};