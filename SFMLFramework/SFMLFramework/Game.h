#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>

#include "Player.h"

namespace sf
{
	class RenderWindow;
}

class Game
{
private:
	sf::RenderWindow* m_pWindow;

	sf::Clock m_clock;

	//sf::CircleShape m_circleShape1;
	//sf::CircleShape m_circleShape2;
	Player m_player;

	void handleWindowsEvents();
	//void initaliseCircles();

	void update( float deltaTime );
	void render();

public:
	Game();
	~Game();

	void run();

};

#endif // End of '#ifndef GAME_H'
