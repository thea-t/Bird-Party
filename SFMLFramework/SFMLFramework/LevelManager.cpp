#include "LevelManager.h"
#include "BasicEnemy.h"
#include "EnemyManager.h"
#include "EnemyType.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

LevelManager::LevelManager()
{
	m_currentLevel = 0;
}

void LevelManager::loadLevel( int level )
{
	std::string levelPath = "Level" + std::to_string(level) + ".txt";
	std::string levelString = readFileIntoString(levelPath);
	std::vector<std::string> splittedString = splitString(levelString);

	int rowCount = splittedString.size();
	int columnCount = splittedString[0].size();

	int i = 0;
	for (size_t y = 0; y < rowCount; y++)
	{
		for (size_t x = 0; x < columnCount; x++)
		{
			// how to convert string to int : https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
			int enemyType = std::stoi(splittedString[y]);

			// how to comvert int to enum class: https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
			pEnemyManager->instantiateEnemy( static_cast<EnemyType>(enemyType), x, y );
			
			i++;

		}
	}
}

void LevelManager::onLevelComplete()
{
	m_currentLevel++;
	loadLevel( m_currentLevel );
}

// how to read .txt files: https://www.delftstack.com/howto/cpp/read-file-into-string-cpp/
std::string LevelManager::readFileIntoString(const std::string& path)
{
	std::ifstream input_file(path);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< path << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

std::vector<std::string> LevelManager::splitString(const std::string& str)
{
	auto result = std::vector<std::string>{};
	auto ss = std::stringstream{ str };

	for (std::string line; std::getline(ss, line, '\n');)
		result.push_back(line);

	return result;
}
