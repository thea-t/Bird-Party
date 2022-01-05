#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Helpers.h"
#include "Settings.h"

Game::Game()
	: m_pWindow( nullptr )
{
	m_pWindow = new sf::RenderWindow( sf::VideoMode( k_windowWidth, k_windowHeight ), "Falconry" );

	// Setup Window frame-rate setting
	m_pWindow->setFramerateLimit( 60 );
	// Enable vertical sync to be on
	m_pWindow->setVerticalSyncEnabled( true );

}

Game::~Game()
{
	SAFE_DELETE( m_pWindow );
}

void Game::handleWindowsEvents()
{
	sf::Event event;
	while( m_pWindow->pollEvent( event ) )
	{
		if( event.type == sf::Event::Closed )
		{
			m_pWindow->close();
		}
	}
}


void Game::run()
{
	m_clock.restart();
	m_levelManager.pEnemyManager = &m_enemyManager;
	m_levelManager.loadLevel(0);
	m_TextureLoader.loadTextures(&m_player, &m_enemyManager);

	while( m_pWindow->isOpen() )
	{
		// Handle all Windows events
		handleWindowsEvents();

		// Clear the Screen
		m_pWindow->clear();
		
		// Get the elapsedTime since last time round
		float elapsedTime = m_clock.restart().asSeconds();
		// Update all objects
		update( elapsedTime );

		// Render all objects
		render();

		// Display all rendered objects
		m_pWindow->display();
	}
} 

void Game::update( float deltaTime )
{
	// update the player
	m_player.update( deltaTime );

	// update the projectiles such as bullets
	for (size_t i = 0; i < m_player.projectileIndex; i++)
	{
		m_player.projectiles[i].update(deltaTime);
	}

	// update the enemies
	for (size_t i = 0; i < m_enemyManager.aliveEnemies.size(); i++)
	{
		m_enemyManager.aliveEnemies[i].update(deltaTime);
	}
}
//function comments
void Game::render()
{
	m_pWindow->draw( m_player );

	for (size_t i = 0; i < m_player.projectileIndex; i++)
	{
		m_pWindow->draw(m_player.projectiles[i]);
	}

	for (size_t i = 0; i < m_enemyManager.aliveEnemies.size(); i++)
	{
		m_pWindow->draw(m_enemyManager.aliveEnemies[i]);
	}

}

