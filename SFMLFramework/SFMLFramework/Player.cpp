#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Settings.h"

Player::Player()
{
	m_delayBetweenSteps = 0.1f;
	m_delayBetweenAttacks = 0.5f;

	currentHealth = maxHealth;

	this->setScale( 0.2, 0.2 );
	this->setPosition( k_windowWidth / 2, k_windowHeight - 130 );
}

Player::~Player()
{
}


void Player::update( float deltaTime )
{
	// count the time passed between each attack
	m_timePassedBetweenAttacks += deltaTime;


	checkCollision();
	
	// read players input and move or shoot accordingly.
	int animationIndex = 0;
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && m_canShoot )
	{
		m_timePassedBetweenAttacks = 0;
		m_canShoot = false;

		// get the player's position and give it some Y offset 
		sf::Vector2f pos = getPosition();
		pos.y -= 30;

		// set the next projectile's position as the same as the offsetted player position
		projectiles[ projectileIndex ].setPosition( pos );

		projectileIndex++;

		//size of an array: https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
		int length = sizeof( projectiles ) / sizeof( projectiles[ 0 ] );
		if ( projectileIndex == length )
		{
			projectileIndex = 0;
		}

		animationIndex = 2;

	}
	// move the player if A or D buttons are pressed
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
	{
		sf::Vector2f pos = getPosition();
		sf::Vector2f scale = getScale();

		pos.x -= k_playerMovementSpeed * deltaTime;

		int minX = 50;

		if ( pos.x < minX )
		{
			pos.x = minX;
		}
		setPosition( pos );

		if ( scale.x < 0 )
		{
			setScale( -scale.x, scale.y );
		}

		animationIndex = 1;
	}

	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
	{
		sf::Vector2f pos = getPosition();
		sf::Vector2f scale = getScale();
		pos.x += k_playerMovementSpeed * deltaTime;
		
		int maxX = 50;

		if ( pos.x > k_arenaWidth - maxX )
		{
			pos.x = k_arenaWidth - maxX;
		}
		setPosition( pos );

		if ( scale.x > 0 )
		{
			setScale( -scale.x, getScale().y );
		}

		animationIndex = 1;
	}
	else if ( !m_canShoot )
	{
		animationIndex = 2;
	}
	else
	{
		animationIndex = 0;
	}

	if ( m_timePassedBetweenAttacks > m_delayBetweenAttacks )
	{
		m_canShoot = true;
	}

	animate( animationIndex, deltaTime );

}

void Player::animate( int animation, float deltaTime )
{
	// count down the time passed between each steps that player makes.
	m_timePassedBetweenSteps += deltaTime;


	if ( animation == 0 )
	{
		// set idle texture
		setTexture( idleTexture );
	}
	else if ( animation == 1 )
	{
		if ( m_timePassedBetweenSteps >= m_delayBetweenSteps )
		{
			if ( m_stepMade )
			{
				// set move1 texture
				setTexture( move1Texture );
				m_stepMade = false;
			}
			else
			{
				// set move2 texture
				setTexture( move2Texture );
				m_stepMade = true;
			}

			m_timePassedBetweenSteps = 0;
		}
	}
	else if ( animation == 2 )
	{
		// set shoot texture
		setTexture( shootTexture );
	}
}

void Player::checkCollision()
{
	// calculate the distance between the player and all other enemies.
	// if an enemy collides with the player, player loses.
	sf::Vector2f pos = getPosition();
	float radius = getRadius( this );

	for ( size_t i = 0; i < pAliveEnemies->size(); i++ )
	{

		Enemy* pEnemy = &( ( *pAliveEnemies )[ i ] );
		sf::Vector2f enemyPosition = pEnemy->getPosition();
		float enemyRadius = getRadius( pEnemy );

		float distance = getDistance( &pos, &enemyPosition );

		if (radius + enemyRadius >= distance ) 
		{
			pEnemy->onGetHit( i );

			currentHealth--;

			if ( currentHealth <= 0 ) 
			{
				*pGameState = GameState::End;
			}

			break;
		}
	}
}

float Player::getRadius( sf::Sprite* sprite )
{
	return ( float )sprite->getTextureRect().height * sprite->getScale().y / 2;

}


//how to calculate the distance between two points: https://www.geeksforgeeks.org/program-calculate-distance-two-points/
float Player::getDistance(sf::Vector2f* a, sf::Vector2f* b) {

	float distance = std::sqrt(std::pow(b->x - a->x, 2) +
		std::pow(b->y - a->y, 2) * 1.0);
	return distance;
}