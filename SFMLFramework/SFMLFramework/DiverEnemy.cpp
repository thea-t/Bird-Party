#include "DiverEnemy.h"
#include "EnemyManager.h"
#include <iostream>

DiverEnemy::DiverEnemy()
{
	move1TexturePath = "Textures/diver-enemy-1.png";
	move2TexturePath = "Textures/diver-enemy-2.png";
	m_scoreGainedOnDeath = m_scoreGainedOnDeath * 3;
	m_divesOnDeath = true;
	m_isDiving = false;
}

DiverEnemy::DiverEnemy( EnemyManager* enemyManager )
{
	move1TexturePath = "Textures/diver-enemy-1.png";
	move2TexturePath = "Textures/diver-enemy-2.png";
	m_scoreGainedOnDeath = m_scoreGainedOnDeath * 3;
	pEnemyManager = enemyManager;
	m_divesOnDeath = true;
	m_isDiving = false;
}
