#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include "Settings.h"

Player::Player()
{
	m_delayBetweenSteps = 0.1;
	m_delayBetweenAttacks = 0.5;

	this->setScale(0.2,0.2);
	this->setPosition(k_windowWidth / 2, k_windowHeight - 100);
}

Player::~Player()
{
}


void Player::update( float deltaTime )
{
	m_timePassedBetweenAttacks += deltaTime;

	int animationIndex = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_canShoot)
	{

		m_timePassedBetweenAttacks = 0;
		m_canShoot = false;

		// get the player's position and give it some Y offset 
		sf::Vector2f pos = getPosition();
		pos.y -= 30;

		// set the next projectile's position as the same as the offsetted player position
		projectiles[projectileIndex].setPosition(pos);

		projectileIndex++;

		//size of an array: https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
		int length = sizeof(projectiles) / sizeof(projectiles[0]);
		if (projectileIndex == length)
		{
			projectileIndex = 0;
		}

		animationIndex = 2;

		//std::cout << std::to_string(projectileIndex) + "\n";
	}
	else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		sf::Vector2f pos = getPosition();
		sf::Vector2f scale = getScale();

		pos.x -= k_playerMovementSpeed * deltaTime;
		if( pos.x < 0.0f )
		{
			pos.x = 0.0f;
		}
		setPosition( pos );

		if (scale.x < 0)
		{
			setScale(-scale.x, scale.y);
		}

		animationIndex = 1;
	}

	else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		sf::Vector2f pos = getPosition();
		sf::Vector2f scale = getScale();
		pos.x += k_playerMovementSpeed * deltaTime;
		if( pos.x > k_arenaWidth )
		{
			pos.x = k_arenaWidth;
		}
		setPosition( pos );

		if (scale.x > 0)
		{
			setScale(-scale.x, getScale().y);
		}

		animationIndex = 1;
	}
	else if( !m_canShoot )
	{
		animationIndex = 2;
	}
	else 
	{
		animationIndex = 0;
	}

	if (m_timePassedBetweenAttacks > m_delayBetweenAttacks)
	{
		m_canShoot = true;
	}

	animate(animationIndex, deltaTime);
}

void Player::animate( int animation, float deltaTime )
{
	m_timePassedBetweenSteps += deltaTime;


	if ( animation == 0 ) 
	{
		// set idle texture
		setTexture( idleTexture );
	}
	else if( animation == 1 )
	{
		if (m_timePassedBetweenSteps >= m_delayBetweenSteps)
		{
			if (m_stepMade) 
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

