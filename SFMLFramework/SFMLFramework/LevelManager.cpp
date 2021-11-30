#include "LevelManager.h"
#include "ForestLevelData.h"
#include "BasicEnemy.h"
#include "EnemyManager.h"

LevelManager::LevelManager()
{
	ForestLevelData forestLevel;
	LoadLevel(forestLevel);
}

void LevelManager::LoadLevel(LevelData level)
{
	int i = 0;
	for (size_t y = 0; y < level.rowCount; y++)
	{
		for (size_t x = 0; x < level.columnCount; x++)
		{
			if (level.enemyConfig[i] == Basic)
			{
				BasicEnemy basicEnemy;
				basicEnemy.setPosition(x,y);
				EnemyManager::aliveEnemies.push_back(basicEnemy);
			}
			
			i++;
		}
	}

	m_currentLevel = level;
}

void LevelManager::OnLevelComplete()
{
}
