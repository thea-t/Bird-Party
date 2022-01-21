#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
}

void ScoreManager::addScore(int amount)
{
	// increase the score by the amount
	currentScore += amount;
}

