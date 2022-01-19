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

	void updateScoreText(int score);

public:
	UIManager();

	LevelManager* pLevelManager;
	Player* pPlayer;
	ScoreManager* pScoreManager;

	sf::Sprite heartSprite [3];
	sf::Texture heartTexture;

	void draw( sf::RenderWindow* pWindow, GameState* gameState);

	void update(float deltaTime, GameState* gameState);

};

#endif