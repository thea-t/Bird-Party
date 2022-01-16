#ifndef ENEMY_H
#define ENEMY_H

#include "GameSprite.h"
#include "EnemyManager.h"
#include "Settings.h"
class EnemyManager;

class Enemy : public GameSprite
{
private:
	int m_movementSpeed;
	float m_minDelayBetweenSteps;
	float m_maxDelayBetweenSteps;
	float m_timePassedBetweenSteps;

	void move( float deltaTime );
	void animate( float deltaTime );

protected:
	EnemyManager* pEnemyManager;
public:
	Enemy();
	Enemy(EnemyManager* enemyManager);
	~Enemy();

	sf::Texture move1Texture;
	sf::Texture move2Texture;
	
	void update( float deltaTime );
};

#endif
