#ifndef PLAYER_H
#define PLAYER_H

#include "GameSprite.h"
#include "Projectile.h"
#include <vector>

class Player : public GameSprite
{
private:
	bool m_shootKeyWasPressed;
	bool m_stepMade;
	int m_currentAnimation;
	float m_elapsedTime;
	float m_animationDelay;

	void animate( int animation, float deltaTime );

public:

	int projectileIndex;
	Projectile projectiles[100];
	Player();
	~Player();

	void update( float deltaTime );
};

#endif