#include "EnemyProjectile.h"
#include "Settings.h"
#include <iostream>

EnemyProjectile::EnemyProjectile()
{
	speed = 150.0f;
	setScale( 0.03f, 0.03f );
}

EnemyProjectile::EnemyProjectile( sf::Vector2f position )
{
	speed = 150.0f;
	setScale( 0.03f, 0.03f );
	setPosition( position );
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::checkCollision()
{
	// get the projectiles position and radius, and calculate a distance between the projectile and the player.
	sf::Vector2f pos = getPosition();
	float radius = getRadius( this );

	sf::Vector2f playerPosition = pPlayerSprite->getPosition();
	float playerRadius = getRadius( pPlayerSprite );

	float distance = getDistance(&pos, &playerPosition);


	// if the distance gets smaller than their radiuses, meaning when they collide, remove player's health
	if ( radius + playerRadius >= distance ) 
	{
		// set the position of the projectile very far away.
		setPosition( k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight );

		int temp = *m_pPlayerHealth;
		temp--;
		*m_pPlayerHealth = temp;

		// if health reaches to 0, end the game.
		if ( temp <= 0 ) 
		{
			*pGameState = GameState::End;
		}
	}
}


