#include "TextureLoader.h"
#include <iostream>

TextureLoader::TextureLoader()
{

}

// how to load textures from path: https://stackoverflow.com/questions/17436544/load-an-image-from-a-relative-path-in-sfml
void TextureLoader::loadTextures( Player* player, EnemyManager* enemyManager, UIManager* uiManager, Background* background )
{
	// load the heart textures.
	uiManager->heartTexture.loadFromFile( "Textures/heart.png" );
	for (size_t i = 0; i < 3; i++)
	{
		setOrigin( &uiManager->heartTexture, &uiManager->heartSprite[ i ] );
		uiManager->heartSprite[ i ].setTexture( uiManager->heartTexture );
	}

	// load the background textures
	for ( size_t i = 0; i < 6; i++ )
	{
		// how to convert string to char* https://stackoverflow.com/questions/7352099/stdstring-to-char/7352131
		int index = i;
		std::string temp = "Textures/Background1/" + std::to_string(index) + ".png";
		const char* path = temp.c_str();
		background->level1Backgrounds[ i ].load( path );
		background->level1Backgrounds[ i ].setPosition( k_arenaWidth /2, k_arenaHeight / 2 );
		background->level1Backgrounds[ i ].setScale( 0.8f, 0.8f );
	}
	for (size_t i = 0; i < 5; i++)
	{
		int index = i;
		std::string temp = "Textures/Background2/" + std::to_string(index) + ".png";
		const char* path = temp.c_str();
		background->level2Backgrounds[ i ].load( path );
		background->level2Backgrounds[ i ].setPosition( k_arenaWidth / 2, k_arenaHeight / 2 );
		background->level2Backgrounds[ i ].setScale( 0.8f, 0.8f );
	}
	for ( size_t i = 0; i < 7; i++ )
	{
		int index = i;
		std::string temp = "Textures/Background3/" + std::to_string(index) + ".png";
		const char* path = temp.c_str();
		background->level3Backgrounds[ i ].load( path );
		background->level3Backgrounds[ i ].setPosition( k_arenaWidth /2, k_arenaHeight / 2 );
		background->level3Backgrounds[ i ].setScale( 0.8f, 0.8f );
	}
	for ( size_t i = 0; i < 5; i++ )
	{
		int index = i;
		std::string temp = "Textures/Background4/" + std::to_string(index) + ".png";
		const char* path = temp.c_str();
		background->level4Backgrounds[ i ].load( path );
		background->level4Backgrounds[ i ].setPosition( k_arenaWidth /2, k_arenaHeight / 2 );
		background->level4Backgrounds[ i ].setScale( 0.8f, 0.8f );
	}
	for ( size_t i = 0; i < 7; i++ )
	{
		int index = i;
		std::string temp = "Textures/Background5/" + std::to_string( index ) + ".png";
		const char* path = temp.c_str();
		background->level5Backgrounds[ i ].load( path );
		background->level5Backgrounds[ i ].setPosition( k_arenaWidth /2, k_arenaHeight / 2 );
		background->level5Backgrounds[ i ].setScale( 0.8f, 0.8f );
	}

	background->menuLogo.load( "Textures/Title.png" );
	background->menuLogo.setPosition( k_arenaWidth / 2, k_arenaHeight / 2 + 150 );

	//load the platform that player stands on
	background->platform.load( "Textures/platform.png" );
	background->platform.setScale( 0.57f, 0.3f );
	background->platform.setPosition( player->getPosition().x, k_arenaHeight - 40 );

	// load the player textures
	player->idleTexture.loadFromFile( "Textures/player_idle.png" );
	player->move1Texture.loadFromFile( "Textures/player_move_1.png" );
	player->move2Texture.loadFromFile( "Textures/player_move_2.png" );
	player->shootTexture.loadFromFile( "Textures/player_shoot.png" );

	// set the origin point of the sprite to the center of the texture.
	// note that all player textures have the same resolution.
	setOrigin( &player->idleTexture, player );

	// load player projectile texture
	player->projectileTexture.loadFromFile( "Textures/projectile_player.png" );

	// load enemy projectile texture
	enemyManager->projectileTexture.loadFromFile( "Textures/projectile_enemy.png" );


	// set all player projectiles the same texture
	// how to get array size: https://www.educative.io/edpresso/how-to-find-the-length-of-an-array-in-cpp
	int playerProjectileSize = sizeof( player->projectiles ) / sizeof( player->projectiles[ 0 ] );
	for ( size_t i = 0; i < playerProjectileSize; i++ )
	{
		player->projectiles[ i ].setTexture( player->projectileTexture );
		setOrigin( &player->projectileTexture, &player->projectiles[ i ] );
	}
	
	// set all enemy projectiles the same texture
	int enemyProjectileSize = sizeof( enemyManager->projectiles ) / sizeof( enemyManager->projectiles[ 0 ] );
	for ( size_t i = 0; i < enemyProjectileSize; i++ )
	{
		enemyManager->projectiles[ i ].setTexture( enemyManager->projectileTexture );
		setOrigin( &enemyManager->projectileTexture, &enemyManager->projectiles[ i ] );
	}

	// load enemy textures
	for ( size_t i = 0; i < enemyManager->aliveEnemies.size(); i++ )
	{
		enemyManager->aliveEnemies[ i ].move1Texture.loadFromFile( enemyManager->aliveEnemies[ i ].move1TexturePath );
		enemyManager->aliveEnemies[ i ].move2Texture.loadFromFile( enemyManager->aliveEnemies[ i ].move2TexturePath );


		enemyManager->aliveEnemies[ i ].setTexture( enemyManager->aliveEnemies[ i ].move1Texture );
		setOrigin( &enemyManager->aliveEnemies[ i ].move1Texture, &enemyManager->aliveEnemies[ i ] );
	}

}


void TextureLoader::setOrigin( sf::Texture* texture, sf::Transformable* object )
{
	// get the texture dimensions and set the origin of the sprite to the center of that texture.
	// this is inspired by the GameSprite class.
	sf::Vector2u textureDimensions = texture->getSize();
	object->setOrigin( static_cast<float>( textureDimensions.x / 2 ),
		static_cast<float>( textureDimensions.y / 2 ) );
}