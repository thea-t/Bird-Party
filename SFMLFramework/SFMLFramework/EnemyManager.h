#include "Enemy.h"
#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

class EnemyManager
{
private:

public:
	EnemyManager();

	static std::vector<Enemy> aliveEnemies;
};

#endif
