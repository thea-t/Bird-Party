#include "EnemyProjectile.h"
#include "Settings.h"
#include <iostream>

EnemyProjectile::EnemyProjectile()
{
	speed = 150.0f;
	setScale(0.03f, 0.03f);
}

EnemyProjectile::EnemyProjectile(sf::Vector2f position)
{
	speed = 150.0f;
	setScale(0.03f, 0.03f);
	setPosition(position);
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::checkCollision()
{
	sf::Vector2f pos = getPosition();
	float radius = getRadius(this);

	sf::Vector2f playerPosition = pPlayerSprite->getPosition();
	float playerRadius = getRadius(pPlayerSprite);

	float distance = getDistance(&pos, &playerPosition);

	if (radius + playerRadius >= distance) {

		// set the position of the projectile very far away.
		setPosition(k_arenaWidth * k_arenaWidth, k_arenaHeight * k_arenaHeight);

		int temp = *pPlayerHealth;
		temp--;
		*pPlayerHealth = temp;
		std::cout << *pPlayerHealth;
	}
}


