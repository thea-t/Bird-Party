#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>

#include "TextureLoader.h"
#include "Player.h"
#include "EnemyManager.h"
#include "LevelManager.h"
#include "AudioLoader.h"
#include "Background.h"
#include "UIManager.h"
//class comment
namespace sf
{
	class RenderWindow;
}

class Game
{
private:
	sf::RenderWindow* m_pWindow;

	// This is the clock used for timing
	sf::Clock m_clock;

	// This is the player instance
	Player m_player;
	UIManager m_uiManager;
	TextureLoader m_TextureLoader;
	//AudioLoader m_audioLoader;
	LevelManager m_levelManager;
	EnemyManager m_enemyManager;
	Background m_background;

	void handleWindowsEvents();


	void update( float deltaTime );

	// this is the render function
	void render();

public:
	Game();
	~Game();

	void run();

};

#endif // End of '#ifndef GAME_H'
