#include "Enemy.h"
#include "DiverEnemy.h"
#include "EnemyManager.h"
#include <iostream>
#include <cstdlib>

Enemy::Enemy()
{
	m_scoreGainedOnDeath = 50;
	m_movementSpeed = 50;
	m_minDelayBetweenSteps = 0.2f;
	m_maxDelayBetweenSteps = 1.0f;
	m_collisionEnabled = true;
	m_divesOnDeath = false;
	m_isAngry = false;
	m_isImmune = false;
}
Enemy::Enemy( EnemyManager* enemyManager )
{
	m_scoreGainedOnDeath = 50;
	m_movementSpeed = 50;
	m_minDelayBetweenSteps = 0.2f;
	m_maxDelayBetweenSteps = 1.0f;
	pEnemyManager = enemyManager;
	m_collisionEnabled = true;
	m_divesOnDeath = false;
	m_isAngry = false;
	m_isImmune = false;
}

Enemy::~Enemy()
{
}

void Enemy::update( float deltaTime )
{
	move( deltaTime );

	animate(deltaTime);
}



void Enemy::move(float deltaTime)
{
	if (m_isDiving) {
		setPosition(getPosition().x, getPosition().y + (m_movementSpeed * deltaTime));

		if (getPosition().y > k_arenaHeight+50) {
			for (size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++)
			{
				if (&pEnemyManager->aliveEnemies[i] == this) {
					pEnemyManager->aliveEnemies.erase(pEnemyManager->aliveEnemies.begin() + i);
					pEnemyManager->refreshEnemies();
					break;
				}
			}

		}
	}
	else {
		if (pEnemyManager->isMovingLeft) {
			setPosition(getPosition().x - (m_movementSpeed * deltaTime), getPosition().y);

			if (getPosition().x <= 40) {


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

			if (getPosition().x >= k_arenaWidth - 40) {


				pEnemyManager->isMovingLeft = true;
				for (size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++)
				{
					pEnemyManager->aliveEnemies[i].setScale(-pEnemyManager->aliveEnemies[i].getScale().x, pEnemyManager->aliveEnemies[i].getScale().y);
					pEnemyManager->aliveEnemies[i].setPosition(pEnemyManager->aliveEnemies[i].getPosition().x, pEnemyManager->aliveEnemies[i].getPosition().y + 35);
				}
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


void Enemy::onGetHit(int hitEnemyIndex)
{
	if (!m_isImmune) {
		
		if (m_divesOnDeath) {
			if (!m_isAngry) {
				m_isAngry = true;
				move1Texture.loadFromFile("Textures/diver-enemy-3.png");
				move2Texture.loadFromFile("Textures/diver-enemy-4.png");
			}
			else {
				move1Texture.loadFromFile("Textures/diver-enemy-5.png");
				move2Texture.loadFromFile("Textures/diver-enemy-6.png");

				pEnemyManager->pScoreManager->addScore(m_scoreGainedOnDeath);
				setRotation(90);

				m_isDiving = true;
				m_isImmune = true;
				m_movementSpeed = m_movementSpeed * 4;
			}

		}
		else {


			pEnemyManager->pScoreManager->addScore(m_scoreGainedOnDeath);
			// how to remove element from a vector: https://www.cplusplus.com/reference/vector/vector/erase/
			// does erasing automatically destroy the object: https://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself#:~:text=Removes%20from%20the%20vector%20container,take%20ownership%20of%20destroying%20it.
			pEnemyManager->aliveEnemies.erase(pEnemyManager->aliveEnemies.begin() + hitEnemyIndex);

		}

		pEnemyManager->pAudioLoader->playRandomBirdHitSound();

		// refreshing the enemies by setting their textures as a fix for flashing enemy textures when an enemy is destroyed.
		pEnemyManager->refreshEnemies();
	}
}
