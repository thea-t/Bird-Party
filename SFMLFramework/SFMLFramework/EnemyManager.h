#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "EnemyProjectile.h"
#include "Enemy.h"
#include "EnemyType.h"
#include "Settings.h"
// solving errors with forward declarations: https://www.learncpp.com/cpp-tutorial/forward-declarations/
class Enemy;
class EnemyProjectile;

class EnemyManager
{
private:
	int m_minShootTime;
	int m_maxShootTime;
	float m_timePassedSinceLastShoot;

	void shootProjectile();

public:
	EnemyManager();

	bool isMovingLeft;
	int projectileIndex;
	std::vector<Enemy> aliveEnemies;
	EnemyProjectile projectiles[100];
	sf::Texture projectileTexture;

	void instantiateEnemy( EnemyType type, int xPos, int yPos );
	void refreshEnemies();
	void update( float deltaTime );
};

#endif
