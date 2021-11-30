#ifndef LEVELDATA_H
#define LEVELDATA_H
#include "EnemyType.h"
#include <map>
#include <SFML/System/Vector2.hpp>

class LevelData
{
public:
	LevelData();

	// maps: https://www.educative.io/edpresso/what-is-the-cpp-stl-map
	std::map<int, EnemyType> enemyConfig;
	int columnCount;
	int rowCount;
};

#endif
