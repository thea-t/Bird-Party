#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "GameSprite.h"

class Background
{
private:
	const int m_cloudSpeed = 55;
public:
	Background();


	GameSprite menuBackground;
	GameSprite level1Backgrounds[6];
	GameSprite level2Backgrounds[7];
	GameSprite level3Backgrounds[8];
	GameSprite level4Backgrounds[5];
	GameSprite level5Backgrounds[7];

	GameSprite platform;


	void draw(sf::RenderWindow* pWindow);
	void update( float deltaTime );

};
#endif
