#include "Background.h"
#include "Settings.h"

Background::Background()
{
}

void Background::draw( sf::RenderWindow* pWindow, GameState* gameState )
{
	// check which game state is currently active and draw backgrounds accordingly.
	if ( *gameState == GameState::Menu ) 
	{
		pWindow->draw( level3Backgrounds[ 0 ] );
		pWindow->draw( menuLogo );
	}
	else if ( *gameState == GameState::Play ) 
	{

		if ( pLevelManager->getCurrentLevel() == 0 ) 
		{
			for ( size_t i = 0; i < 6; i++ )
			{
				pWindow->draw( level1Backgrounds[ i ] );
			}
		}
		else if ( pLevelManager->getCurrentLevel() == 1 ) 
		{
			for ( size_t i = 0; i < 5; i++ )
			{
				pWindow->draw( level2Backgrounds[i] );
			}
		}
		else if ( pLevelManager->getCurrentLevel() == 2 ) 
		{
			for ( size_t i = 0; i < 7; i++ )
			{
				pWindow->draw( level3Backgrounds[ i ] );
			}
		}
		else if ( pLevelManager->getCurrentLevel() == 3 ) 
		{
			for ( size_t i = 0; i < 5; i++ )
			{
				pWindow->draw( level4Backgrounds[ i ] );
			}
		}
		else if ( pLevelManager->getCurrentLevel() == 4 ) 
		{
			for ( size_t i = 0; i < 7; i++ )
			{
				pWindow->draw( level5Backgrounds[ i ] );
			}
		}

		// draw the platform that the player stands on regardless of the level.
		pWindow->draw( platform );
	}

}

void Background::update( float deltaTime, GameState* gameState )
{

	// check if the game is in Play state. If so, animate the clouds of the current level in order to achieve parallax effect.
	if ( *gameState == GameState:: Play ) 
	{
		if (pLevelManager->getCurrentLevel() == 0) {
			int cloud1Index = 4;
			int cloud2Index = 5;
			level1Backgrounds[cloud1Index].setPosition(level1Backgrounds[cloud1Index].getPosition().x - m_cloudSpeed * 0.6f * deltaTime, level1Backgrounds[cloud1Index].getPosition().y);
			level1Backgrounds[cloud2Index].setPosition(level1Backgrounds[cloud2Index].getPosition().x - m_cloudSpeed * deltaTime, level1Backgrounds[cloud2Index].getPosition().y);

			if (level1Backgrounds[cloud1Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level1Backgrounds[cloud1Index].setPosition(k_arenaWidth * 1.5f, level1Backgrounds[cloud1Index].getPosition().y);
			}
			if (level1Backgrounds[cloud2Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level1Backgrounds[cloud2Index].setPosition(k_arenaWidth * 1.5f, level1Backgrounds[cloud2Index].getPosition().y);
			}
		}
		else if (pLevelManager->getCurrentLevel() == 1) {
			int cloud1Index = 3;
			int cloud2Index = 4;
			level2Backgrounds[cloud1Index].setPosition(level2Backgrounds[cloud1Index].getPosition().x - m_cloudSpeed * 0.6f * deltaTime, level2Backgrounds[cloud1Index].getPosition().y);
			level2Backgrounds[cloud2Index].setPosition(level2Backgrounds[cloud2Index].getPosition().x - m_cloudSpeed * deltaTime, level2Backgrounds[cloud2Index].getPosition().y);

			if (level2Backgrounds[cloud1Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level2Backgrounds[cloud1Index].setPosition(k_arenaWidth * 1.5f, level2Backgrounds[cloud1Index].getPosition().y);
			}
			if (level2Backgrounds[cloud2Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level2Backgrounds[cloud2Index].setPosition(k_arenaWidth * 1.5f, level2Backgrounds[cloud2Index].getPosition().y);
			}
		}
		else if (pLevelManager->getCurrentLevel() == 2) {
			int cloud1Index = 5;
			int cloud2Index = 6;
			level3Backgrounds[cloud1Index].setPosition(level3Backgrounds[cloud1Index].getPosition().x - m_cloudSpeed * 0.6f * deltaTime, level3Backgrounds[cloud1Index].getPosition().y);
			level3Backgrounds[cloud2Index].setPosition(level3Backgrounds[cloud2Index].getPosition().x - m_cloudSpeed * deltaTime, level3Backgrounds[cloud2Index].getPosition().y);

			if (level3Backgrounds[cloud1Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level3Backgrounds[cloud1Index].setPosition(k_arenaWidth * 1.5f, level3Backgrounds[cloud1Index].getPosition().y);
			}
			if (level3Backgrounds[cloud2Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level3Backgrounds[cloud2Index].setPosition(k_arenaWidth * 1.5f, level3Backgrounds[cloud2Index].getPosition().y);
			}
		}
		else if (pLevelManager->getCurrentLevel() == 3) {
			int cloud1Index = 3;
			int cloud2Index = 4;
			level4Backgrounds[cloud1Index].setPosition(level4Backgrounds[cloud1Index].getPosition().x - m_cloudSpeed * 0.6f * deltaTime, level4Backgrounds[cloud1Index].getPosition().y);
			level4Backgrounds[cloud2Index].setPosition(level4Backgrounds[cloud2Index].getPosition().x - m_cloudSpeed * deltaTime, level4Backgrounds[cloud2Index].getPosition().y);

			if (level4Backgrounds[cloud1Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level4Backgrounds[cloud1Index].setPosition(k_arenaWidth * 1.5f, level4Backgrounds[cloud1Index].getPosition().y);
			}
			if (level4Backgrounds[cloud2Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level4Backgrounds[cloud2Index].setPosition(k_arenaWidth * 1.5f, level4Backgrounds[cloud2Index].getPosition().y);
			}
		}
		else if (pLevelManager->getCurrentLevel() == 4) {
			int cloud1Index = 5;
			int cloud2Index = 6;
			level5Backgrounds[cloud1Index].setPosition(level5Backgrounds[cloud1Index].getPosition().x - m_cloudSpeed * 0.6f * deltaTime, level5Backgrounds[cloud1Index].getPosition().y);
			level5Backgrounds[cloud2Index].setPosition(level5Backgrounds[cloud2Index].getPosition().x - m_cloudSpeed * deltaTime, level5Backgrounds[cloud2Index].getPosition().y);

			if (level5Backgrounds[cloud1Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level5Backgrounds[cloud1Index].setPosition(k_arenaWidth * 1.5f, level5Backgrounds[cloud1Index].getPosition().y);
			}
			if (level5Backgrounds[cloud2Index].getPosition().x <= -k_arenaWidth / 2)
			{
				level5Backgrounds[cloud2Index].setPosition(k_arenaWidth * 1.5f, level5Backgrounds[cloud2Index].getPosition().y);
			}
		}
	}
	
}
