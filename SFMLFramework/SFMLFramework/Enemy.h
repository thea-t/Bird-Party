#ifndef ENEMY_H
#define ENEMY_H

#include "GameSprite.h"

class Enemy : public GameSprite
{

public:
	Enemy();

	const char* path;
	sf::Texture idleTexture;

	void move();
	void update( float deltaTime );
};

#endif
