#include <iostream>
#include "EnemyManager.h"
#include "BasicEnemy.h"
#include "BonusEnemy.h"
#include "DiverEnemy.h"


EnemyManager::EnemyManager()
{
	shootTime = 3;
}


void EnemyManager::instantiateEnemy( EnemyType type , int xPos, int yPos )
{
	// create a new instance of an enemy by the given type at the given position
	if ( type == EnemyType::Basic )
	{
		BasicEnemy* basicEnemy = new BasicEnemy( this );
		basicEnemy->setScale( 0.1f, 0.1f );
		basicEnemy->setPosition( xPos* 80 + 50, yPos * 70 + 80 );
		aliveEnemies.push_back(*basicEnemy);
	}
	else if ( type == EnemyType::Bonus ) 
	{
		BonusEnemy* bonusEnemy = new BonusEnemy( this );
		bonusEnemy->setScale( 0.1f, 0.1f );
		bonusEnemy->setPosition( xPos * 80 + 50, yPos * 70 + 80 );
		aliveEnemies.push_back( *bonusEnemy );
	}

	else if ( type == EnemyType::Diver ) 
	{
		DiverEnemy* diverEnemy = new DiverEnemy( this );
		diverEnemy->setScale( 0.1f, 0.1f );
		diverEnemy->setPosition( xPos * 80 + 50, yPos * 70 + 80 );
		aliveEnemies.push_back( *diverEnemy );
	}
}

void EnemyManager::refreshEnemies()
{
	// this is called everytime an enemy is erased from aliveEnemies vector.
	// it is done to prevent enemies flashing.
	if ( aliveEnemies.size() == 0 ) 
	{
		*pGameState = GameState::Win;
	}

	for ( size_t i = 0; i < aliveEnemies.size(); i++ )
	{
		// how to get a random boolean: https://stackoverflow.com/questions/43329352/generating-random-boolean/43329456
		bool _rand = 0 + ( rand() % ( 1 - 0 + 1 )) == 1;

		if ( _rand ) 
		{
			aliveEnemies[ i ].setTexture( aliveEnemies[ i ].move1Texture );
		}
		else 
		{
			aliveEnemies[ i ].setTexture( aliveEnemies[ i ].move2Texture );
		}
	}
}

void EnemyManager::update( float deltaTime )
{
	// count the time passed between each shoots and shoot every some time.
	m_timePassedSinceLastShoot += deltaTime;

	if ( shootTime <= m_timePassedSinceLastShoot ) 
	{
		if ( aliveEnemies.size() > 0 ) 
		{
			shootProjectile();
		}
		m_timePassedSinceLastShoot = 0;
	}
}

void EnemyManager::shootProjectile()
{
	// randomly pick an alive enemy and shoot from it.
	int _rand = rand() % aliveEnemies.size();

	projectiles[ projectileIndex ].setPosition( aliveEnemies[ _rand ].getPosition() );
	
	projectileIndex++;


	//size of an array: https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
	int length = sizeof( projectiles ) / sizeof( projectiles[ 0 ] );
	if ( projectileIndex == length )
	{
		projectileIndex = 0;
	}

}
