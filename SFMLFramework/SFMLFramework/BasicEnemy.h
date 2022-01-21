#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "Enemy.h"

class BasicEnemy : public Enemy
{

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Sets the pointer that directs to Enemy Manager. Sets the texture paths.
//    Parameters    :    EnemyManager*
//    Returns        :    None
//    Notes        :     None
//    See also    :    LevelManager::loadLevel();
//#######################################################
	BasicEnemy();
	BasicEnemy(EnemyManager* enemyManager);


};

#endif
