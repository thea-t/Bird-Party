#ifndef PLAYERPROJECTILE_H
#define PLAYERPROJECTILE_H

#include "Projectile.h"
#include "EnemyManager.h"

class EnemyManager;

class PlayerProjectile : public Projectile
{
private:
	void checkCollision() override;
public:
	PlayerProjectile();
	PlayerProjectile(sf::Vector2f position);
	~PlayerProjectile();

	EnemyManager* pEnemyManager;
};

#endif
