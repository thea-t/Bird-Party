#ifndef PLAYERPROJECTILE_H
#define PLAYERPROJECTILE_H

#include "Projectile.h"
#include "EnemyManager.h"

class PlayerProjectile : public Projectile
{
private:
	void checkCollision() override;
public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Sets the speed, scale and the position of this projectile.
//    Parameters    :    Vector2f
//    Returns        :    None
//    Notes        :     None
//    See also    :    Player::update();
//#######################################################
	PlayerProjectile();
	PlayerProjectile(sf::Vector2f position);
	~PlayerProjectile();

	EnemyManager* pEnemyManager;
};

#endif
