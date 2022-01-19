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
	Background();


	GameSprite menuBackground;
	GameSprite level1Backgrounds[6];
	GameSprite level2Backgrounds[5];
	GameSprite level3Backgrounds[7];
	GameSprite level4Backgrounds[5];
	GameSprite level5Backgrounds[7];

	GameSprite platform;

	LevelManager* pLevelManager;


	void draw(sf::RenderWindow* pWindow, GameState* gameState);
	void update(float deltaTime, GameState* gameState);

};
#endif
	