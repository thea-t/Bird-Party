#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile()
{
	speed = -150.0f;
	setScale( 0.3f, 0.3f );
}

PlayerProjectile::PlayerProjectile( sf::Vector2f position )
{
	speed = -150.0f;
	setScale( 0.3f, 0.3f );
	setPosition( position );
}

PlayerProjectile::~PlayerProjectile()
{
}

void PlayerProjectile::checkCollision()
{
	// get the projectiles position and radius, and calculate a distance between the projectile and all enemies.
	sf::Vector2f pos = getPosition();
	float radius = getRadius( this );

	for ( size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++ )
	{
		Enemy* pEnemy = &pEnemyManager->aliveEnemies[ i ];
		sf::Vector2f enemyPosition = pEnemy->getPosition();
		float enemyRadius = getRadius( pEnemy );

		float distance = getDistance( &pos, &enemyPosition );

		// if any enemy collides with this projectile, call their onGetHit() function
		if ( radius + enemyRadius >= distance ) 
		{
			// set the position of the projectile very far away.
			setPosition( k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight );

			pEnemyManager->aliveEnemies[ i ].onGetHit( i );

			break;
		}
	}
	
	// also check if this projectile collides with an enemy projectile.
	// move both projectiles away so that they don't go over each other.
	for ( size_t i = 0; i < 100 ; i++ )
	{
		EnemyProjectile* enemyProjectile = &pEnemyManager->projectiles[ i ];
		sf::Vector2f enemyProjectilePosition = enemyProjectile->getPosition();
		float enemyProjectileRadius = getRadius( enemyProjectile );

		float distance = getDistance( &pos, &enemyProjectilePosition ); 
		
		if ( radius + enemyProjectileRadius >= distance ) 
		{
			// set the position of the projectile very far away.
			setPosition( k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight );
			enemyProjectile->setPosition( k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight );

			break;
		}
	}
}

