#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H


#include "Projectile.h"
#include "GameState.h"


class EnemyProjectile : public Projectile
{
private:
	void checkCollision() override;

	int* m_pPlayerHealth;

public:
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