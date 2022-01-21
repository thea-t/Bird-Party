#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile()
{
	speed = -150.0f;
	setScale(0.3f, 0.3f);
}

PlayerProjectile::PlayerProjectile(sf::Vector2f position)
{
	speed = -150.0f;
	setScale(0.3f, 0.3f);
	setPosition(position);
}

PlayerProjectile::~PlayerProjectile()
{
}

void PlayerProjectile::checkCollision()
{
	sf::Vector2f pos = getPosition();
	float radius = getRadius(this);

	for (size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++)
	{
		Enemy* pEnemy = &pEnemyManager->aliveEnemies[i];
		sf::Vector2f enemyPosition = pEnemy->getPosition();
		float enemyRadius = getRadius(pEnemy);

		float distance = getDistance(&pos, &enemyPosition);

		if (radius + enemyRadius >= distance) {

			// set the position of the projectile very far away.
			setPosition(k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight);

			pEnemyManager->aliveEnemies[i].onGetHit( i );

			break;
		}
	}

	for (size_t i = 0; i < 100 ; i++)
	{
		EnemyProjectile* enemyProjectile = &pEnemyManager->projectiles[i];
		sf::Vector2f enemyProjectilePosition = enemyProjectile->getPosition();
		float enemyProjectileRadius = getRadius(enemyProjectile);

		float distance = getDistance(&pos, &enemyProjectilePosition); 
		
		if (radius + enemyProjectileRadius >= distance) {
			
			// set the position of the projectile very far away.
			setPosition(k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight);
			enemyProjectile->setPosition(k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight);

			break;
		}
	}
}

