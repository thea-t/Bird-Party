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

	// load projectile texture
	player->projectileTexture.loadFromFile("projectile_player.png");


	// set all projectiles the same texture
	// how to get array size: https://www.educative.io/edpresso/how-to-find-the-length-of-an-array-in-cpp
	int projectileSize = sizeof(player->projectiles) / sizeof(player->projectiles[0]);
	for (size_t i = 0; i < projectileSize; i++)
	{
		player->projectiles[i].setTexture(player->projectileTexture);
		setOrigin(&player->projectileTexture, &player->projectiles[i]);
	}

	// load enemy textures
	for (size_t i = 0; i < enemyManager->aliveEnemies.size(); i++)
	{
		enemyManager->aliveEnemies[i].load(enemyManager->aliveEnemies[i].path);
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