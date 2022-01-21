#ifndef ENEMY_H
#define ENEMY_H

#include "GameSprite.h"
#include "Settings.h"

// solving errors with forward declarations: https://www.learncpp.com/cpp-tutorial/forward-declarations/
class EnemyManager;

class Enemy : public GameSprite
{
private:
	float m_minDelayBetweenSteps;
	float m_maxDelayBetweenSteps;
	float m_timePassedBetweenSteps;
	bool m_isImmune;
	bool m_collisionEnabled;

//#######################################################
//    Function    :    Animate
//    Purpose        :    Swaps textures every x seconds to animate the sprite.
//    Parameters    :    float
//    Returns        :    None
//    Notes        :     None
//    See also    :    Enemy::update();
//#######################################################
	void animate( float deltaTime );

//#######################################################
//    Function    :    Move
//    Purpose        :    Moves the enemy towards a direction.
//    Parameters    :    float
//    Returns        :    None
//    Notes        :     None
//    See also    :    Enemy::update();
//#######################################################
	void move(float deltaTime);

protected:
	bool m_isAngry;
	bool m_isDiving;
	bool m_divesOnDeath;
	int m_movementSpeed;
	int m_scoreGainedOnDeath;
	EnemyManager* pEnemyManager;


public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes enemy parameters.
//    Parameters    :    EnemyManager*
//    Returns        :    None
//    Notes        :     None
//    See also    :    LevelManager::loadLevel();
//#######################################################
	Enemy();
	Enemy( EnemyManager* enemyManager );
	~Enemy();

	const char* move1TexturePath;
	const char* move2TexturePath;
	sf::Texture move1Texture;
	sf::Texture move2Texture;

//#######################################################
//    Function    :    Update
//    Purpose        :    Updates the enemy every frame. Is called by the Game.
//    Parameters    :    float
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update();
//#######################################################
	 void update( float deltaTime );

//#######################################################
//    Function    :    OnGetHit
//    Purpose        :    Is called when the player hits this enemy.
//    Parameters    :    int
//    Returns        :    None
//    Notes        :     None
//    See also    :    PlayerProjectile::checkCollision();
//#######################################################
	 void onGetHit(int hitEnemyIndex);
};

#endif
