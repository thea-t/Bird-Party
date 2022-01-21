#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "GameSprite.h"
#include "GameState.h"
#include "LevelManager.h"

class Background
{
private:
	const int m_cloudSpeed = 20;
public:
//#######################################################
//    Function    :     Constructor
//    Purpose        :    Initializes the background.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::run();
//#######################################################
	Background();


	GameSprite menuBackground;
	GameSprite level1Backgrounds[6];
	GameSprite level2Backgrounds[5];
	GameSprite level3Backgrounds[7];
	GameSprite level4Backgrounds[5];
	GameSprite level5Backgrounds[7];

	GameSprite platform;

	LevelManager* pLevelManager;

//#######################################################
//    Function    :    Draw
//    Purpose        :    Draws the background sprites.
//    Parameters    :    RenderWindow*, GameState*
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::draw();
//#######################################################
	void draw(sf::RenderWindow* pWindow, GameState* gameState);

//#######################################################
//    Function    :    Update
//    Purpose        :    Moves the clouds in the background.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update();
//#######################################################
	void update(float deltaTime, GameState* gameState);

};
#endif
	