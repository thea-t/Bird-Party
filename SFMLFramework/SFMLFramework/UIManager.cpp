#include "UIManager.h"
#include <iostream>

UIManager::UIManager()
{
	sf::FloatRect textRect;
	m_menuTextSpeed = 0.4f;

	for (size_t i = 0; i < 3; i++)
	{
		heartSprite[i].setPosition(30 * (i + 1), 30);
		heartSprite[i].setScale(0.1f, 0.1f);
	}

	// how to render text in sfml: https://www.sfml-dev.org/tutorials/2.5/graphics-text.php
	m_font.loadFromFile("Fonts/Sweet Saturday.ttf");

	// set the score text properties
	m_scoreText.setFont(m_font);
	m_scoreText.setString("Score: 0");
	m_scoreText.setCharacterSize(27);
	m_scoreText.setStyle(sf::Text::Bold);
	m_scoreText.setOutlineThickness(2.0f);
	m_scoreText.setPosition(200, 10);

	// set the win text properties
	m_levelPassedText.setFont(m_font);
	m_levelPassedText.setString("Level Completed! Press [SPACE] to continue");
	m_levelPassedText.setCharacterSize(34);
	m_levelPassedText.setStyle(sf::Text::Bold);
	m_levelPassedText.setOutlineThickness(2.0f);
	m_levelPassedText.setPosition(k_arenaWidth / 2, 200);
	// how to align text in center: https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
	textRect = m_levelPassedText.getLocalBounds();
	m_levelPassedText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	// set the lose text properties
	m_youDiedText.setFont(m_font);
	m_youDiedText.setString("Level failed! Press [SPACE] to return to the menu.");
	m_youDiedText.setCharacterSize(34);
	m_youDiedText.setStyle(sf::Text::Bold);
	m_youDiedText.setOutlineThickness(2.0f);
	m_youDiedText.setPosition(k_arenaWidth / 2, 200);
	textRect = m_youDiedText.getLocalBounds();
	m_youDiedText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	// set the menu text properties
	m_menuText.setFont(m_font);
	m_menuText.setString("Press [SPACE] to start");
	m_menuText.setCharacterSize(24);
	m_menuText.setStyle(sf::Text::Bold);
	m_menuText.setOutlineThickness(2.0f);
	m_menuText.setPosition(k_arenaWidth / 2, 200);
	 textRect = m_menuText.getLocalBounds();
	m_menuText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}

void UIManager::draw(sf::RenderWindow* pWindow, GameState* gameState)
{
	if (*gameState == GameState::Menu) {
		pWindow->draw(m_menuText);
	}
	else if (*gameState == GameState::Play) {
		for (size_t i = 0; i < pPlayer->currentHealth; i++)
		{
			pWindow->draw(heartSprite[i]);
		}

		updateScoreText(pScoreManager->currentScore);
		pWindow->draw(m_scoreText);
	}
	else if (*gameState == GameState::Win) {
		pWindow->draw(m_levelPassedText);
	}
	else if (*gameState == GameState::Lose) {
		pWindow->draw(m_youDiedText);
	}
}

void UIManager::update(float deltaTime, GameState* gameState)
{
	if (*gameState == GameState::Menu) {


		if (m_menuText.getScale().x > m_menuTextMaxScale) {
			m_menuTextSpeed = -0.4f;
		}
		else if(m_menuText.getScale().x < m_menuTextMinScale){
			m_menuTextSpeed = 0.4f;
		}

		m_menuText.setScale(m_menuText.getScale().x + m_menuTextSpeed * deltaTime, m_menuText.getScale().y + m_menuTextSpeed * deltaTime);


		// check if space button is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			*gameState = GameState::Play;
		}
	}
	else if (*gameState == GameState::Win) {
		// check if space button is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			pLevelManager->onLevelComplete();
			*gameState = GameState::Play;
		}
	}
	else if (*gameState == GameState::Lose) {
		// check if space button is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			*gameState = GameState::Menu;
		}
	}
}

void UIManager::updateScoreText(int score)
{
	// how to convert int to string: https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
	m_scoreText.setString("Score: " + std::to_string(score));
}

