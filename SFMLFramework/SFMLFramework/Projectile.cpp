#include "Projectile.h"
#include "Settings.h"

Projectile::Projectile( )
{
	load("projectile_player.png");
	m_speed = 150;
	setScale(0.05, 0.05);
}

Projectile::Projectile( sf::Vector2f position )
{
	load("projectile_player.png");
	m_speed = 150;
	setScale(0.05, 0.05);
	setPosition( position );
}

Projectile::~Projectile()
{
}


void Projectile::update(float deltaTime)
{
	sf::Vector2f pos = getPosition();
	pos.y -= m_speed * deltaTime;
	setPosition(pos);
}