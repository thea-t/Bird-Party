#include <iostream>

#include "GameSprite.h"

GameSprite::GameSprite()
{

}

GameSprite::~GameSprite()
{

}

bool GameSprite::load( const char* fileName )
{

	bool loaded = m_texture.loadFromFile( fileName );
	if( loaded )
	{
		setTexture( m_texture );

		// Set the handle of the sprite to be the center 
		sf::Vector2u textureDimensions = m_texture.getSize();
		setOrigin( static_cast<float>( textureDimensions.x/2 ),
				   static_cast<float>( textureDimensions.y/2 ) );
	}
	else
	{
		std::cout << "Failed to load '" << fileName << "'\n";
	}

	return loaded;
}
