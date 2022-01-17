#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class UIManager
{
private:
	sf::Font m_font;
	sf::Text m_scoreText;

	void updateScoreText(int score);

public:
	UIManager();

	Player* pPlayer;
	ScoreManager* pScoreManager;

	sf::Sprite heartSprite [3];
	sf::Texture heartTexture;

	void draw( sf::RenderWindow* pWindow );

};

#endif