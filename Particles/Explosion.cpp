#include "Explosion.h"

Explosion::Explosion(float x, float y)
	:Particles(Configure::explosionLifeTime, Configure::explosionSprite, 
		Configure::tanksTexture, Configure::explosionSpriteRect, Configure::explosionWidth, 
		Configure::explosionWidth, Configure::explosionAnimationFrames, Configure::explosionAnimationTime,
		x, y)
{
}
