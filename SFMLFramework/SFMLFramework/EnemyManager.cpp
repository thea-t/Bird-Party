#include "EnemyManager.h"
#include "BasicEnemy.h"
#include <iostream>
#include "Settings.h"

EnemyManager::EnemyManager()
{
}

void EnemyManager::instantiateEnemy( EnemyType type , int xPos, int yPos )
{
	if ( type == Basic)
	{
		BasicEnemy pBasicEnemy;
		pBasicEnemy.setScale(0.1, 0.1);
		// TODO: come up with something better that suits multiple lines being instantiated
		pBasicEnemy.setPosition(xPos* 100 + 400, yPos * 100 + 200 );
		aliveEnemies.push_back(pBasicEnemy);

	}
	else if (type == Bonus) {

	}

	else if (type == Fighter) {

	}

	else if (type == Diver) {

	}

	else if (type == Rebirth) {

	}
}
