#include "Projectile.h"
#include "Settings.h"

Projectile::Projectile( )
{
	load("projectile_player.png");
	m_speed = 2;
	setScale(0.3, 0.3); 
}

Projectile::Projectile( sf::Vector2f position )
{
	load("projectile_player.png");
	m_speed = 2;
	setScale(0.3, 0.3);
	setPosition( position );
}

Projectile::~Projectile()
{
}


void Projectile::update(float deltaTime)
{
	sf::Vector2f pos = getPosition();
	pos.y += m_speed * deltaTime;
	setPosition(pos);

	if (pos.y > k_arenaHeight / 2)
	{
		delete this;
	}
}