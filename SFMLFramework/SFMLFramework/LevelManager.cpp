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
	pAudioLoader->loadMusic("Audios/music-" + std::to_string(level) + ".wav");

	std::string levelPath = "Levels/Level" + std::to_string(level) + ".txt";
	std::string levelString = readFileIntoString(levelPath);
	std::vector<std::string> splittedString = splitString( levelString );

	int rowCount = splittedString.size();
	int columnCount = splittedString[ 0 ].size();

	int i = 0;
	for ( size_t y = 0; y < rowCount; y++ )
	{
		for ( size_t x = 0; x < columnCount; x++ )
		{
			// check if a char is numeric: https://www.cplusplus.com/reference/cctype/isdigit/
			if ( isdigit( splittedString[ y ][ x ] ) ) {

				// how to convert string to int : https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
				int enemyType = splittedString[ y ][ x ] - '0';

				// how to convert int to enum class: https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
				pEnemyManager->instantiateEnemy( static_cast<EnemyType>( enemyType ), x, y );
				pEnemyManager->isMovingLeft = false;
			}

			i++;

		}
	}
}

void LevelManager::onLevelComplete()
{

	// increase the current level and increase the enemies movement and shooting speed 
	m_currentLevel++;

	pEnemyManager->shootTime = pEnemyManager->shootTime - pEnemyManager->shootTime / 5;


	if ( m_currentLevel == 5 ) {
		// game over
		*pGameState = GameState::End;
		m_currentLevel = 0;
	}
	else 
	{
		loadLevel( m_currentLevel );

		// reload enemy textures and increase their movement speed
		for (size_t i = 0; i < pEnemyManager->aliveEnemies.size(); i++)
		{
			pEnemyManager->aliveEnemies[i].setMovementSpeed(pEnemyManager->aliveEnemies[i].getMovementSpeed() + m_currentLevel * 4);

			pEnemyManager->aliveEnemies[i].move1Texture.loadFromFile(pEnemyManager->aliveEnemies[i].move1TexturePath);
			pEnemyManager->aliveEnemies[i].move2Texture.loadFromFile(pEnemyManager->aliveEnemies[i].move2TexturePath);


			pEnemyManager->aliveEnemies[i].setTexture(pEnemyManager->aliveEnemies[i].move1Texture);
			sf::Vector2u textureDimensions = pEnemyManager->aliveEnemies[i].move1Texture.getSize();
			pEnemyManager->aliveEnemies[i].setOrigin(static_cast<float>(textureDimensions.x / 2),
				static_cast<float>(textureDimensions.y / 2));
		}
	}
}

// how to read .txt files: https://www.delftstack.com/howto/cpp/read-file-into-string-cpp/
// both readFileIntoString() and splitString() functions were created from this link
std::string LevelManager::readFileIntoString( const std::string& path )
{
	std::ifstream input_file( path );
	if ( !input_file.is_open() ) {
		std::cerr << "Could not open the file - '"
			<< path << "'" << std::endl;
		exit( EXIT_FAILURE );
	}
	return std::string( ( std::istreambuf_iterator<char>( input_file ) ), std::istreambuf_iterator<char>() );
}

std::vector<std::string> LevelManager::splitString( const std::string& str )
{
	auto result = std::vector<std::string>{};
	auto ss = std::stringstream{ str };

	for ( std::string line; std::getline( ss, line, '\n' ); )
		result.push_back( line );

	return result;
}
