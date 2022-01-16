#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H


#include "Projectile.h"
//#include "Player.h"


class EnemyProjectile : public Projectile
{
private:
	void checkCollision() override;

public:
	EnemyProjectile();
	EnemyProjectile( sf::Vector2f position );
	~EnemyProjectile();

	sf::Sprite* pPlayerSprite;

};

#endif