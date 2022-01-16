#include "BasicEnemy.h"
#include "Enemy.h"

BasicEnemy::BasicEnemy()
{
}

BasicEnemy::BasicEnemy(EnemyManager* enemyManager)
{
	pEnemyManager = enemyManager;
}
