#ifndef PLAYER_H
#define PLAYER_H

#include "GameSprite.h"

class Player : public GameSprite
{
private:

public:
	Player();
	~Player();

	void update( float deltaTime );
};

#endif // End of '#ifndef PLAYER_H'
