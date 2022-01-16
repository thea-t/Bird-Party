#ifndef PLAYER_H
#define PLAYER_H

#include "GameSprite.h"
#include "PlayerProjectile.h"
#include <vector>

class PlayerProjectile;

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

	void animate( int animation, float deltaTime );

public:

	Player();
	~Player();

	int projectileIndex;
	PlayerProjectile projectiles[100];

	sf::Texture idleTexture;
	sf::Texture move1Texture;
	sf::Texture move2Texture;
	sf::Texture shootTexture;
	sf::Texture projectileTexture;


	void update( float deltaTime );
};

#endif