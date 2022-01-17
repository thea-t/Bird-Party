#include "UIManager.h"

UIManager::UIManager()
{
	for (size_t i = 0; i < 3; i++)
	{
		heartSprite[i].setPosition(30 * (i + 1), 30);
		heartSprite[i].setScale(0.1f, 0.1f);
	}

	// how to render text in sfml: https://www.sfml-dev.org/tutorials/2.5/graphics-text.php
	m_font.loadFromFile("Fonts/Sweet Saturday.ttf");
	m_scoreText.setFont(m_font);
	m_scoreText.setString("Score: 0");
	m_scoreText.setCharacterSize(27);
	m_scoreText.setStyle(sf::Text::Bold);
	m_scoreText.setOutlineThickness(2.0f);
	m_scoreText.setPosition(200, 10);
}

void UIManager::draw(sf::RenderWindow* pWindow)
{
	for (size_t i = 0; i < pPlayer->currentHealth; i++)
	{
		pWindow->draw(heartSprite[i]);
	}

	updateScoreText(pScoreManager->currentScore);
	pWindow->draw(m_scoreText);

}

void UIManager::updateScoreText(int score)
{
	// how to convert int to string: https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
	m_scoreText.setString("Score: " + std::to_string(score));
}

