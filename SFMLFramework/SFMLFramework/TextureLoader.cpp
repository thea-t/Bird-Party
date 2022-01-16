#include "TextureLoader.h"


TextureLoader::TextureLoader()
{

}

// how to load textures from path: https://stackoverflow.com/questions/17436544/load-an-image-from-a-relative-path-in-sfml
void TextureLoader::loadTextures(Player* player, EnemyManager* enemyManager)
{

	// load the player textures
	player->idleTexture.loadFromFile("player_idle.png");
	player->move1Texture.loadFromFile("player_move_1.png");
	player->move2Texture.loadFromFile("player_move_2.png");
	player->shootTexture.loadFromFile("player_shoot.png");

	// set the origin point of the sprite to the center of the texture.
	// note that all player textures have the same resolution.
	setOrigin(&player->idleTexture, player);

	// load player projectile texture
	player->projectileTexture.loadFromFile("projectile_player.png");

	// load enemy projectile texture
	enemyManager->projectileTexture.loadFromFile("projectile_enemy.png");


	// set all player projectiles the same texture
	// how to get array size: https://www.educative.io/edpresso/how-to-find-the-length-of-an-array-in-cpp
	int playerProjectileSize = sizeof(player->projectiles) / sizeof(player->projectiles[0]);
	for (size_t i = 0; i < playerProjectileSize; i++)
	{
		player->projectiles[i].setTexture(player->projectileTexture);
		setOrigin(&player->projectileTexture, &player->projectiles[i]);
	}
	
	// set all enemy projectiles the same texture
	int enemyProjectileSize = sizeof(enemyManager->projectiles) / sizeof(enemyManager->projectiles[0]);
	for (size_t i = 0; i < enemyProjectileSize; i++)
	{
		enemyManager->projectiles[i].setTexture(enemyManager->projectileTexture);
		setOrigin(&enemyManager->projectileTexture, &enemyManager->projectiles[i]);
	}

	// load enemy textures
	for (size_t i = 0; i < enemyManager->aliveEnemies.size(); i++)
	{
		enemyManager->aliveEnemies[i].move1Texture.loadFromFile("basic-enemy-1.png");
		enemyManager->aliveEnemies[i].move2Texture.loadFromFile("basic-enemy-2.png");

		enemyManager->aliveEnemies[i].setTexture(enemyManager->aliveEnemies[i].move1Texture);
		setOrigin(&enemyManager->aliveEnemies[i].move1Texture, &enemyManager->aliveEnemies[i]);
	}

}

void TextureLoader::setOrigin(sf::Texture* texture, sf::Transformable* object)
{
	// get the texture dimensions and set the origin of the sprite to the center of that texture.
	// this is inspired by the GameSprite class.
	sf::Vector2u textureDimensions = texture->getSize();
	object->setOrigin(static_cast<float>(textureDimensions.x / 2),
		static_cast<float>(textureDimensions.y / 2));
}