#include <SFML/Window/Keyboard.hpp>

#include "Player.h"
#include "Settings.h"

Player::Player()
{
}

Player::~Player()
{
}


void Player::update( float deltaTime )
{
	//sf::Vector2f scale = m_gameSprite.getScale();

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		sf::Vector2f pos = getPosition();
		pos.x -= k_playerMovementSpeed * deltaTime;
		if( pos.x < 0.0f )
		{
			pos.x = 0.0f;
		}
		setPosition( pos );
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		sf::Vector2f pos = getPosition();
		pos.x += k_playerMovementSpeed * deltaTime;
		if( pos.x > k_arenaWidth )
		{
			pos.x = k_arenaWidth;
		}
		setPosition( pos );
	}


	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		sf::Vector2f pos = getPosition();
		pos.y -= k_playerMovementSpeed * deltaTime;
		if( pos.y < 0.0f )
		{
			pos.y = 0.0f;
		}
		setPosition( pos );
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		sf::Vector2f pos = getPosition();
		pos.y += k_playerMovementSpeed * deltaTime;
		if( pos.y > k_arenaHeight )
		{
			pos.y = k_arenaHeight;
		}
		setPosition( pos );
	}
}
