#ifndef PLAYER_H
#define PLAYER_H

#include "GameSprite.h"
#include "Projectile.h"
#include <vector>

class Player : public GameSprite
{
private:
	bool m_stepMade;
	int m_currentAnimation;
	float m_elapsedTime;
	float m_animationDelay;

	void animate( int animation, float deltaTime );

public:

	std::vector< Projectile > m_projectiles;
	Player();
	~Player();

	void update( float deltaTime );
};

#endif // End of '#ifndef PLAYER_H'
