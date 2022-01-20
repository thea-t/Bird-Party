#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include "EnemyManager.h"

Enemy::Enemy()
{
	m_scoreGainedOnDeath = 50;
	m_movementSpeed = 50;
	m_minDelayBetweenSteps = 0.2f;
	m_maxDelayBetweenSteps = 1.0f;
}
Enemy::Enemy( EnemyManager* enemyManager )
{
	m_scoreGainedOnDeath = 50;
	m_movementSpeed = 50;
	m_minDelayBetweenSteps = 0.2f;
	m_maxDelayBetweenSteps = 1.0f;
	pEnemyManager = enemyManager;
}

Enemy::~Enemy()
{
}

void Enemy::update( float deltaTime )
{
	move( deltaTime );

	animate(deltaTime);
}
void Enemy::onHit( int hitEnemyIndex )
{

	// how to remove element from a vector: https://www.cplusplus.com/reference/vector/vector/erase/
	// does erasing automatically destroy the object: https://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself#:~:text=Removes%20from%20the%20vector%20container,take%20ownership%20of%20destroying%20it.
	pEnemyManager->aliveEnemies.erase(pEnemyManager->aliveEnemies.begin() + hitEnemyIndex);

	// refreshing the enemies by setting their textures as a fix for flashing enemy textures when an enemy is destroyed.
	pEnemyManager->refreshEnemies();

	pEnemyManager->pScoreManager->addScore( m_scoreGainedOnDeath );
}


void Enemy::move(float deltaTime)
{
	if (pEnemyManager->isMovingLeft) {
		setPosition(getPosition().x - (m_movementSpeed * deltaTime), getPosition().y);

		if (getPosition().x <= move1Texture.getSize().x / 2) {


			// cannot convert bool to bool*: https://stackoverflow.com/questions/2939286/error-c2440-cannot-convert-from-bool-to-bool/2939292
			pEnemyManager->isMovingLeft = false;
			for (size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++)
			{
				pEnemyManager->aliveEnemies[i].setScale(-pEnemyManager->aliveEnemies[i].getScale().x, pEnemyManager->aliveEnemies[i].getScale().y);
				pEnemyManager->aliveEnemies[i].setPosition(pEnemyManager->aliveEnemies[i].getPosition().x, pEnemyManager->aliveEnemies[i].getPosition().y + 35);
			}
		}
	}
	else {
		setPosition(getPosition().x + (m_movementSpeed * deltaTime), getPosition().y);

		if (getPosition().x >= k_arenaWidth + move1Texture.getSize().x / 2) {


			pEnemyManager->isMovingLeft = true;
			for (size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++)
			{
				pEnemyManager->aliveEnemies[i].setScale(-pEnemyManager->aliveEnemies[i].getScale().x, pEnemyManager->aliveEnemies[i].getScale().y);
				pEnemyManager->aliveEnemies[i].setPosition(pEnemyManager->aliveEnemies[i].getPosition().x, pEnemyManager->aliveEnemies[i].getPosition().y + 35);
			}
		}    
	}
}

void Enemy::animate(float deltaTime)
{
	m_timePassedBetweenSteps += deltaTime;

	// how to get a random value between two values: https://www.cplusplus.com/reference/cstdlib/rand/
	// i multiplied it by 100 in order to use it as integer and then divided it later to get it as float because random only works with integers.
	float randomDelay = ((float)(rand() % (int)(m_maxDelayBetweenSteps * 100) + (int)(m_minDelayBetweenSteps * 100))) / 100;

	if (m_timePassedBetweenSteps >= randomDelay) {

		if (getTexture() == &move1Texture) {
			setTexture(move2Texture);
		}
		else {
			setTexture(move1Texture);
		}
		m_timePassedBetweenSteps = 0;

	}
}


