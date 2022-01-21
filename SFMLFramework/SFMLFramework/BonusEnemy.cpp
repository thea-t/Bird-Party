#include "BonusEnemy.h"
#include "EnemyManager.h"

BonusEnemy::BonusEnemy()
{
	m_scoreGainedOnDeath = m_scoreGainedOnDeath * m_scoreMultiplier;

	move1TexturePath = "Textures/bonus-enemy-1.png";
	move2TexturePath = "Textures/bonus-enemy-2.png";
}

BonusEnemy::BonusEnemy( EnemyManager* enemyManager )
{
	m_scoreGainedOnDeath = m_scoreGainedOnDeath * m_scoreMultiplier;

	move1TexturePath = "Textures/bonus-enemy-1.png";
	move2TexturePath = "Textures/bonus-enemy-2.png";
	pEnemyManager = enemyManager;
}
