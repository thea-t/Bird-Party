#include "ForestLevelData.h"
#include <iostream>

ForestLevelData::ForestLevelData()
{
	columnCount = 6;
	rowCount = 3;

	int enemyCount = columnCount * rowCount;

	for (size_t i = 0; i < enemyCount; i++)
	{
		enemyConfig.insert(std::pair<int, EnemyType>(i, Basic));
	}

	std::cout << "FFFFFF \n";
}
