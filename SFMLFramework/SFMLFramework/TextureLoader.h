#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SFML/Graphics/Texture.hpp>
#include "Player.h"
#include "EnemyManager.h"

class TextureLoader
{
private:
	void setOrigin( sf::Texture* texture, sf::Transformable* object );

public:
	TextureLoader();

	// how to swap textures: https://en.sfml-dev.org/forums/index.php?topic=11382.0
	void loadTextures( Player* player, EnemyManager* enemyManager);
};
#endif
