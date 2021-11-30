#include "LevelData.h"
#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H


class LevelManager
{
private:
	LevelData m_currentLevel;

public:
	LevelManager();

	void LoadLevel( LevelData level );
	void OnLevelComplete();
};

#endif
