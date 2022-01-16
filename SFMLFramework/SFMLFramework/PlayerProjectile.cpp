#include "PlayerProjectile.h"
#include "CollisionMath.h"

PlayerProjectile::PlayerProjectile()
{
	speed = -150.0f;
	setScale(0.03f, 0.03f);
}

PlayerProjectile::PlayerProjectile(sf::Vector2f position)
{
	speed = -150.0f;
	setScale(0.03f, 0.03f);
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
		Enemy* enemy = &pEnemyManager->aliveEnemies[i];
		sf::Vector2f enemyPosition = enemy->getPosition();
		float enemyRadius = getRadius(enemy);

		float distance = getDistance(&pos, &enemyPosition);

		if (radius + enemyRadius >= distance) {
			// how to remove element from a vector: https://www.cplusplus.com/reference/vector/vector/erase/
			// does erasing automatically destroy the object: https://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself#:~:text=Removes%20from%20the%20vector%20container,take%20ownership%20of%20destroying%20it.
			pEnemyManager->aliveEnemies.erase(pEnemyManager->aliveEnemies.begin() + i);

			// refreshing the enemies by setting their textures as a fix for flashing enemy textures when an enemy is destroyed.
			pEnemyManager->refreshEnemies();

			// set the position of the projectile very far away.
			setPosition(k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight);

			break;
		}
	}
}

