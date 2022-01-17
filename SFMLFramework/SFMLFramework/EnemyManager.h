#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "EnemyProjectile.h"
#include "Enemy.h"
#include "EnemyType.h"
#include "Settings.h"
#include "ScoreManager.h"


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

	ScoreManager* pScoreManager;

	void instantiateEnemy( EnemyType type, int xPos, int yPos );
	void refreshEnemies();
	void update( float deltaTime );
};

#endif
