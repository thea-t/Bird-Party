#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <string>
#include <vector>
#include "EnemyManager.h"
#include "GameState.h"
#include "AudioLoader.h"

class LevelManager
{
private:
	int m_currentLevel;

//#######################################################
//    Function    :    ReadFileIntoString
//    Purpose        :    Gets the data of a text file as string.
//    Parameters    :    const string&
//    Returns        :    string
//    Notes        :     None
//    See also    :    LevelManager::loadLevel()
//#######################################################
	std::string readFileIntoString(const std::string& path);

//#######################################################
//    Function    :    SplitString
//    Purpose        :    Splits a string from each row into a vector of multiple strings.
//    Parameters    :    const string&
//    Returns        :    vector<string>
//    Notes        :     None
//    See also    :    LevelManager::loadLevel()
//#######################################################
	std::vector<std::string> splitString(const std::string& str);

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the level manager.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run()
//#######################################################
	LevelManager();

	void setCurrentLevel(int level)
	{
		m_currentLevel = level;
	}
	int getCurrentLevel()
	{
		return m_currentLevel;
	}

//#######################################################
//    Function    :    LoadLevel
//    Purpose        :    Loads a level from text files.
//    Parameters    :    int
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run()
//#######################################################
	void loadLevel( int level );

//#######################################################
//    Function    :    OnLevelComplete
//    Purpose        :    Changes the level to the next one. Is called every time a level is cleared.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    UIManager::update()
//#######################################################
	void onLevelComplete();

	EnemyManager* pEnemyManager;
	GameState* pGameState;
	AudioLoader* pAudioLoader;

};

#endif
