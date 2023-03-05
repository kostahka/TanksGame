#include "Wall.h"

Wall::Wall(WallType type, float x, float y)
	:GameObject(Configure::wallWidth, Configure::wallWidth, Configure::wallMaxHp, Configure::wallSprite, x, y,
		type != WallType::Wall), type(type)
{
	switch (type)
	{
	case WallType::Wall:
		SetSprite(Configure::wallSprite);
		break;
	case WallType::Immortal:
		SetSprite(Configure::immortalWallSprite);
		break;
	case WallType::Water:
		SetSprite(Configure::waterSprite);
		break;
	case WallType::Grass:
		SetSprite(Configure::grassSprite);
		break;
	default:
		break;
	}
}

WallType Wall::getType() const
{
	return type;
}
