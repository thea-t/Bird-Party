#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <string>
#include <vector>
#include "EnemyManager.h"
#include "GameState.h"

class LevelManager
{
private:
	int m_currentLevel;

	std::string readFileIntoString(const std::string& path);
	std::vector<std::string> splitString(const std::string& str);

public:
	LevelManager();

	void setCurrentLevel(int level)
	{
		m_currentLevel = level;
	}
	int getCurrentLevel()
	{
		return m_currentLevel;
	}

	void loadLevel( int level );
	void onLevelComplete();

	EnemyManager* pEnemyManager;
	GameState* pGameState;

};

#endif
