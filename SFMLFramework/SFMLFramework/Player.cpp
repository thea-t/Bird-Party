#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include "Settings.h"

Player::Player()
{
	m_animationDelay = 0.1;
	this->setScale(0.3,0.3);
	this->setPosition(k_windowWidth / 2, k_windowHeight - 100);
}

Player::~Player()
{
}


void Player::update( float deltaTime )
{
	int animationIndex = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_shootKeyWasPressed)
	{
		m_shootKeyWasPressed = true;

		sf::Vector2f pos = getPosition();
		pos.y -= 50;

		projectiles[projectileIndex].setPosition(pos);

		projectileIndex++;
		//size of an array: https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
		if (projectileIndex == sizeof(projectiles) / sizeof(projectiles[0]))
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
	else 
	{
		animationIndex = 0;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_shootKeyWasPressed = false;
	}

	animate(animationIndex, deltaTime);
}

void Player::animate( int animation, float deltaTime )
{
	m_elapsedTime += deltaTime;


	if ( animation == 0 ) 
	{
		//////////////////////
		load( "player_idle.png" );
	}
	else if( animation == 1 )
	{
		if (m_elapsedTime >= m_animationDelay)
		{
			if (m_stepMade) 
			{
				this->load( "player_move_1.png" );
				m_stepMade = false;
			}
			else 
			{
				this->load( "player_move_2.png" );
				m_stepMade = true;
			}

			m_elapsedTime = 0;
		}
	}
	else if ( animation == 2 ) 
	{
		this->load("player_shoot.png");
	}
}

