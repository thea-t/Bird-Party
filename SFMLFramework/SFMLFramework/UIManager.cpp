#include "UIManager.h"

UIManager::UIManager()
{
	for (size_t i = 0; i < 3; i++)
	{
		heartSprite[i].setPosition(30 * (i+ 1), 30);
		heartSprite[i].setScale(0.1f, 0.1f);
	}
}

void UIManager::draw(sf::RenderWindow* pWindow)
{
	for (size_t i = 0; i < pPlayer->currentHealth; i++)
	{
		pWindow->draw(heartSprite[i]);
	}
}

