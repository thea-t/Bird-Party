#include <iostream>
#include "EnemyManager.h"
#include "BasicEnemy.h"


EnemyManager::EnemyManager()
{
	m_minShootTime = 3;
	m_maxShootTime = 6;
}


void EnemyManager::instantiateEnemy( EnemyType type , int xPos, int yPos)
{


	if ( type == Basic)
	{
		BasicEnemy* basicEnemy = new BasicEnemy(this);
		basicEnemy->setScale(0.1f, 0.1f);
		basicEnemy->setPosition(xPos* 80 + 50, yPos * 70 + 80);
		aliveEnemies.push_back(*basicEnemy);

		std::cout << aliveEnemies.size() << "\n";
	}
	/*else if (type == Bonus) {

	}

	else if (type == Fighter) {

	}

	else if (type == Diver) {

	}

	else if (type == Rebirth) {

	}*/
}

void EnemyManager::refreshEnemies()
{
	if (aliveEnemies.size() == 0) {
		*pGameState = GameState::Win;
	}

	for (size_t i = 0; i < aliveEnemies.size(); i++)
	{
		// how to get a random boolean: https://stackoverflow.com/questions/43329352/generating-random-boolean/43329456
		bool _rand = 0 + (rand() % (1 - 0 + 1)) == 1;

		if (_rand) {
			aliveEnemies[i].setTexture(aliveEnemies[i].move1Texture);
		}
		else {
			aliveEnemies[i].setTexture(aliveEnemies[i].move2Texture);
		}
	}
}

void EnemyManager::update(float deltaTime)
{
	m_timePassedSinceLastShoot += deltaTime;

	int shootTime = rand() % m_maxShootTime + m_minShootTime;

	if (shootTime <= m_timePassedSinceLastShoot) {

		if (aliveEnemies.size() > 0) {
			shootProjectile();
		}
		m_timePassedSinceLastShoot = 0;
	}

}

void EnemyManager::shootProjectile()
{
	int _rand = rand() % aliveEnemies.size();

	projectiles[projectileIndex].setPosition(aliveEnemies[_rand].getPosition());

	projectileIndex++;

	//size of an array: https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
	int length = sizeof(projectiles) / sizeof(projectiles[0]);
	if (projectileIndex == length)
	{
		projectileIndex = 0;
	}

}
