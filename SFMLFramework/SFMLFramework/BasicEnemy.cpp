#include "BasicEnemy.h"
#include "EnemyManager.h"

BasicEnemy::BasicEnemy()
{
	move1TexturePath = "Textures/basic-enemy-1.png";
	move2TexturePath = "Textures/basic-enemy-2.png";
}

BasicEnemy::BasicEnemy(EnemyManager* enemyManager)
{
	move1TexturePath = "Textures/basic-enemy-1.png";
	move2TexturePath = "Textures/basic-enemy-2.png";
	pEnemyManager = enemyManager;
}

