#include "Game.h"

Game::Game()
	: m_pWindow(nullptr)
{
	m_pWindow = new sf::RenderWindow(sf::VideoMode(k_windowWidth, k_windowHeight), "Falconry");

	// Setup Window frame-rate setting
	m_pWindow->setFramerateLimit(60);
	// Enable vertical sync to be on
	m_pWindow->setVerticalSyncEnabled(true);

}

Game::~Game()
{
	SAFE_DELETE(m_pWindow);
}

void Game::handleWindowsEvents()
{
	sf::Event event;
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_pWindow->close();
		}
	}
}


void Game::run()
{
	m_clock.restart();

	m_gameState = GameState::Menu;

	for (size_t i = 0; i < 100; i++)
	{
		m_player.projectiles[i].pEnemyManager = &m_enemyManager;
		m_enemyManager.projectiles[i].pPlayerSprite = &m_player;
		m_enemyManager.projectiles[i].pGameState = &m_gameState;
		m_enemyManager.projectiles[i].setPlayerHealth(&m_player.currentHealth);
	}
	m_levelManager.pEnemyManager = &m_enemyManager;
	m_uiManager.pPlayer = &m_player;
	m_uiManager.pLevelManager = &m_levelManager;
	m_uiManager.pScoreManager = &m_scoreManager;
	m_enemyManager.pScoreManager = &m_scoreManager;
	m_enemyManager.pGameState = &m_gameState;
	m_background.pLevelManager = &m_levelManager;

	m_levelManager.loadLevel(0);
	m_TextureLoader.loadTextures(&m_player, &m_enemyManager, &m_uiManager, &m_background);
	m_audioLoader.loadAudio("Audios/Menu #8 (Looped).wav");

	while (m_pWindow->isOpen())
	{
		// Handle all Windows events
		handleWindowsEvents();

		// Clear the Screen
		m_pWindow->clear();

		// Get the elapsedTime since last time round
		float elapsedTime = m_clock.restart().asSeconds();
		// Update all objects
		update(elapsedTime);

		// Render all objects
		render();

		// Display all rendered objects
		m_pWindow->display();
	}
}

void Game::update(float deltaTime)
{
	// update the background
	m_background.update(deltaTime, &m_gameState);
	m_uiManager.update(deltaTime, &m_gameState);

	if (m_gameState == GameState::Play) {
		// update the player
		m_player.update(deltaTime);

		// update the enemy manager
		m_enemyManager.update(deltaTime);


		// update the enemies
		for (size_t i = 0; i < m_enemyManager.aliveEnemies.size(); i++)
		{
			m_enemyManager.aliveEnemies[i].update(deltaTime);
		}
		// update the player projectiles
		for (int i = 0; i < m_player.projectileIndex; i++)
		{
			m_player.projectiles[i].update(deltaTime);
		}
		// update enemy projectiles
		for (size_t i = 0; i < m_enemyManager.projectileIndex; i++)
		{
			m_enemyManager.projectiles[i].update(deltaTime);
		}
	}

}
//function comments
void Game::render()
{
	m_background.draw(m_pWindow, &m_gameState);

	if (m_gameState == GameState::Menu) {

	}
	else if (m_gameState == GameState::Play) {


		m_pWindow->draw(m_player);

		for (size_t i = 0; i < m_enemyManager.projectileIndex; i++)
		{
			m_pWindow->draw(m_enemyManager.projectiles[i]);
		}

		for (size_t i = 0; i < m_enemyManager.aliveEnemies.size(); i++)
		{
			m_pWindow->draw(m_enemyManager.aliveEnemies[i]);
		}
		for (size_t i = 0; i < m_player.projectileIndex; i++)
		{
			m_pWindow->draw(m_player.projectiles[i]);
		}

	}

	m_uiManager.draw(m_pWindow, &m_gameState);
}

