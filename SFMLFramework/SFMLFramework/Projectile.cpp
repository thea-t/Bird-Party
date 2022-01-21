#include "Projectile.h"
#include <iostream>

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
// this is empty because EnemyProjectile and PlayerProjectile overrides it differently.	
}


float Projectile::getRadius(sf::Sprite* sprite)
{
	// calculate the radius of this sprite by dividing its height to 2
	return (float)sprite->getTextureRect().height * sprite->getScale().y / 2;
}


//how to calculate the distance between two points: https://www.geeksforgeeks.org/program-calculate-distance-two-points/
float Projectile::getDistance(sf::Vector2f* a, sf::Vector2f* b) {

	float distance = std::sqrt(std::pow(b->x - a->x, 2) +
		std::pow(b->y - a->y, 2) * 1.0);
	return distance;
}
