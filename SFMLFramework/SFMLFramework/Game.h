#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>

#include "Player.h"
#include "EnemyManager.h"
#include "LevelManager.h"

namespace sf
{
	class RenderWindow;
}

class Game
{
private:
	sf::RenderWindow* m_pWindow;

	sf::Clock m_clock;
	Player m_player;
	LevelManager m_levelManager;
	void handleWindowsEvents();

	void update( float deltaTime );
	void render();

public:
	Game();
	~Game();

	void run();

};

#endif // End of '#ifndef GAME_H'
