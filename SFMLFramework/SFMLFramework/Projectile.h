#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameSprite.h"

class Projectile : public GameSprite
{
private:
	float m_speed;
	
public:
	Projectile();
	Projectile( sf::Vector2f position );
	~Projectile();

	void update(float deltaTime);
};

#endif
