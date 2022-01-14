#include "Projectile.h"
#include "Settings.h"

Projectile::Projectile( )
{
	m_speed = 150.0f;
	setScale(0.03f, 0.03f);
}

Projectile::Projectile( sf::Vector2f position )
{
	m_speed = 150.0f;
	setScale(0.03f, 0.03f);
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