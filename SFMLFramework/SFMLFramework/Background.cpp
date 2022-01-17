#include "Background.h"
#include "Settings.h"

Background::Background()
{
}

void Background::draw(sf::RenderWindow* pWindow)
{
	for (size_t i = 0; i < 6; i++)
	{
		pWindow->draw(level1Backgrounds[i]);
	}
	pWindow->draw(platform);
}

void Background::update(float deltaTime)
{
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
