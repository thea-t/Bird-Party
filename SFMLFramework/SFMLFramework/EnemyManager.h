#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "Enemy.h"
#include "EnemyType.h"
#include "BasicEnemy.h"

class EnemyManager
{
private:

public:
	EnemyManager();

	std::vector<Enemy> aliveEnemies;

	BasicEnemy basicEnemy;
	void instantiateEnemy( EnemyType type, int xPos, int yPos);
};

#endif
