#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H


#include "Projectile.h"
#include "Player.h"

class Player;

class EnemyProjectile : public Projectile
{
private:
	void checkCollision() override;

public:
	EnemyProjectile();
	EnemyProjectile( sf::Vector2f position );
	~EnemyProjectile();

	Player* pPlayer;

};

#endif