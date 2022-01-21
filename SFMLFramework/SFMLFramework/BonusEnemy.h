#ifndef BONUSENEMY_H
#define BONUSENEMY_H

#include "Enemy.h"

class BonusEnemy : public Enemy
{

private:
	const int m_scoreMultiplier = 5;

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Sets the pointer that directs to Enemy Manager. Sets the texture paths and multiplies score gained.
//    Parameters    :    EnemyManager*
//    Returns        :    None
//    Notes        :     None
//    See also    :    LevelManager::loadLevel();
//#######################################################
	BonusEnemy();
	BonusEnemy( EnemyManager* enemyManager );

};

#endif
