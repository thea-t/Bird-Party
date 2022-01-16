#include "Projectile.h"

Projectile::Projectile( )
{
}

Projectile::Projectile( sf::Vector2f position )
{
	setPosition( position );
}

Projectile::~Projectile()
{
}



void Projectile::update(float deltaTime)
{
	sf::Vector2f pos = getPosition();
	pos.y += speed * deltaTime;
	setPosition(pos);

	checkCollision();
}

void Projectile::checkCollision()
{
	
}
