#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Player.h"
#include "GameState.h"
#include "LevelManager.h"

class UIManager
{
private:
	const float m_menuTextMaxScale = 2.0f;
	const float m_menuTextMinScale = 1.6f;
	float m_menuTextSpeed;

	sf::Font m_font;
	sf::Text m_scoreText;
	sf::Text m_menuText;
	sf::Text m_youDiedText;
	sf::Text m_levelPassedText;

sf::RenderWindow* m_pWindow;

//#######################################################
//    Function    :    UpdateScoreText
//    Purpose        :    Sets a new value to the score text.
//    Parameters    :    int
//    Returns        :    None
//    Notes        :     None
//    See also    :    UIManager::draw()
//#######################################################
	void updateScoreText(int score);

public:
//#######################################################
//    Function    :    Constructor
//    Purpose        :    Initializes the UI Manager
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run()
//#######################################################
	UIManager();

	LevelManager* pLevelManager;
	Player* pPlayer;
	ScoreManager* pScoreManager;

	sf::Sprite heartSprite [3];
	sf::Texture heartTexture;

//#######################################################
//    Function    :    Draw
//    Purpose        :    Draws all UI elements on the screen.
//    Parameters    :    RenderWindow*, GameState*
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::draw()
//#######################################################
	void draw( sf::RenderWindow* pWindow, GameState* gameState);

//#######################################################
//    Function    :    Update
//    Purpose        :    Updates UI animations such as the menu text.
//    Parameters    :    float, GameState*
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update()
//#######################################################
	void update( float deltaTime, GameState* gameState );

};

#endif