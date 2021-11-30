#ifndef ENEMY_H
#define ENEMY_H

#include "GameSprite.h"

class Enemy : public GameSprite
{

public:
	Enemy();

	const char* path;
};

#endif
