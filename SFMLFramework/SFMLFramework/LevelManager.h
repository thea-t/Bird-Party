#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <string>
#include <vector>
#include "EnemyManager.h"

class LevelManager
{
private:
	int m_currentLevel;

	std::string readFileIntoString(const std::string& path);
	std::vector<std::string> splitString(const std::string& str);

public:
	LevelManager();

	void loadLevel( int level );
	void onLevelComplete();

	EnemyManager* pEnemyManager;
};

#endif