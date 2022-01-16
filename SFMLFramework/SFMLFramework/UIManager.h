#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class UIManager
{
private:

public:
	UIManager();

	Player* pPlayer;

	sf::Sprite heartSprite [3];
	sf::Texture heartTexture;

	void draw( sf::RenderWindow* pWindow );
};

#endif