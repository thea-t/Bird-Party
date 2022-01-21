#ifndef DIVERENEMY_H
#define DIVERENEMY_H

#include "Enemy.h"

class DiverEnemy : public Enemy
{
private:

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the enemy.
//    Parameters    :    EnemyManager*
//    Returns        :    None
//    Notes        :     None
//    See also    :    LevelManager::loadLevel();
//#######################################################
	DiverEnemy();
	DiverEnemy(EnemyManager* enemyManager);

};

#endif
