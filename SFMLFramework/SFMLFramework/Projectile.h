#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameSprite.h"

class Projectile : public GameSprite
{
private:
	virtual void checkCollision();

protected:
	float speed;

public:
	Projectile();
	Projectile( sf::Vector2f position );
	~Projectile();

	void update(float deltaTime);
};

#endif
