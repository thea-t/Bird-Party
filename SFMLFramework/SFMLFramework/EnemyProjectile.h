#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H


#include "Projectile.h"
#include "GameState.h"


class EnemyProjectile : public Projectile
{
private:
//#######################################################
//    Function    :    CheckCollision
//    Purpose        :    Checks if this projectile collides with the player. Is called every frame.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Projectile::update();
//#######################################################
	void checkCollision() override;

	int* m_pPlayerHealth;

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Sets the speed, scale and the position of this projectile.
//    Parameters    :    Vector2f
//    Returns        :    None
//    Notes        :     None
//    See also    :    EnemyManager::shootProjectile();
//#######################################################
	EnemyProjectile();
	EnemyProjectile( sf::Vector2f position );
	~EnemyProjectile();

	sf::Sprite* pPlayerSprite;
	GameState* pGameState;

	void setPlayerHealth(int* pPlayerHealth)
	{
		m_pPlayerHealth = pPlayerHealth;
	}

	int* getPlayerHealth()
	{
		return m_pPlayerHealth;
	}
};

#endif