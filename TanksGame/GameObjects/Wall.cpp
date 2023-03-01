#include "Wall.h"

Wall::Wall(float x, float y)
	:GameObject(Configure::wallWidth, Configure::wallWidth, Configure::wallMaxHp, Configure::wallSprite, x, y)
{

}
