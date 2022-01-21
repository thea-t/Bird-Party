#ifndef PLAYER_H
#define PLAYER_H

#include "GameSprite.h"
#include "PlayerProjectile.h"

//class PlayerProjectile;

class Player : public GameSprite
{
private:
	bool m_canShoot;
	bool m_stepMade;
	int m_currentAnimation;
	float m_timePassedBetweenSteps;
	float m_delayBetweenSteps;
	float m_timePassedBetweenAttacks;
	float m_delayBetweenAttacks;

//#######################################################
//    Function    :    Animate
//    Purpose        :    Switches players textures to create animations.
//    Parameters    :    int, float
//    Returns        :    None
//    Notes        :     None
//    See also    :    Player::update()
//#######################################################
	void animate( int animation, float deltaTime );

//#######################################################
//    Function    :    CheckCollision
//    Purpose        :    Checks if the player collides with any enemies. If so, loses the game.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Player::update()
//#######################################################
	void checkCollision();
	
//#######################################################
//    Function    :    GetRadius
//    Purpose        :    Returns the radius of a sprite. Used to check collisions.
//    Parameters    :    Sprite*
//    Returns        :    float
//    Notes        :     None
//    See also    :    Player::checkCollision()
//#######################################################
	float getRadius( sf::Sprite* sprite );

//#######################################################
//    Function    :    GetDistance
//    Purpose        :    Returns distance between two points. Used to check collisions.
//    Parameters    :    Vector2f*, Vector2f*
//    Returns        :    float
//    Notes        :     None
//    See also    :    Player::checkCollision()
//#######################################################
	float getDistance( sf::Vector2f* a, sf::Vector2f* b );

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the player
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run()
//#######################################################
	Player();
	~Player();

	int projectileIndex;
	const int maxHealth = 3;
	int currentHealth;

	PlayerProjectile projectiles[100];

	sf::Texture idleTexture;
	sf::Texture move1Texture;
	sf::Texture move2Texture;
	sf::Texture shootTexture;
	sf::Texture projectileTexture;

	std::vector<Enemy>* pAliveEnemies;
	GameState* pGameState;

//#######################################################
//    Function    :    Update
//    Purpose        :    Updates the player every frame. Checks for key input.
//    Parameters    :    float
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update();
//#######################################################
	void update( float deltaTime );
};

#endif