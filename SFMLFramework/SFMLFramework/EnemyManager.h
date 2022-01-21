#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "EnemyProjectile.h"
#include "Enemy.h"
#include "EnemyType.h"
#include "Settings.h"
#include "ScoreManager.h"
#include "GameState.h"
#include "AudioLoader.h"


class EnemyManager
{
private:
	float m_timePassedSinceLastShoot;

//#######################################################
//    Function    :    ShootProjectile
//    Purpose        :    Randomly selects an enemy and shoots a projectile from it.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    
//#######################################################
	void shootProjectile();

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the enemy manager
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	EnemyManager();

	bool isMovingLeft;
	int shootTime;
	int projectileIndex;
	std::vector<Enemy> aliveEnemies;
	EnemyProjectile projectiles[100];
	sf::Texture projectileTexture;

	GameState* pGameState;
	ScoreManager* pScoreManager;
	AudioLoader* pAudioLoader;

//#######################################################
//    Function    :    InstantiateEnemy
//    Purpose        :    Creates a new instance of an enemy.
// 	  Parameters      :    EnemyType, int, int
//    Returns        :    None
//    Notes        :     None
//    See also    :    LevelManager::loadLevel();
//#######################################################
	void instantiateEnemy( EnemyType type, int xPos, int yPos );

//#######################################################
//    Function    :    RefreshEnemies
//    Purpose        :    Resets the textures of all enemies.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     This was done in order to fix the issue with flashing textures.
//    See also    :    Enemy::onGetHit();
//#######################################################
	void refreshEnemies();

//#######################################################
//    Function    :    Update
//    Purpose        :    Shoots a projectile some every second. Is called every frame. 
//    Parameters    :    float
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update();
//#######################################################
	void update( float deltaTime );
};

#endif
