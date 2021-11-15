#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Helpers.h"
#include "Settings.h"

Game::Game()
	: m_pWindow( nullptr )
{
	m_pWindow = new sf::RenderWindow( sf::VideoMode( k_windowWidth, k_windowHeight ), "Zafs amazing Framework!" );

	// Setup Window frame-rate setting
	//m_pWindow->setFramerateLimit( 60 );
	// Enable vertical sync to be on
	//m_pWindow->setVerticalSyncEnabled( true );

	// Setup all Game variables
//	initaliseCircles();

	m_player.load( "dog.png" );
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

//void Game::initaliseCircles()
//{
//	m_circleShape1.setRadius( 50.0f );
//	m_circleShape1.setFillColor( sf::Color::Green );
//	m_circleShape1.setPointCount( 100 );
//
//	m_circleShape2.setRadius( 100.0f );
//	m_circleShape2.setFillColor( sf::Color::Blue );
//}

void Game::run()
{
	m_clock.restart();
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
	m_player.update( deltaTime );
	//std::cout << deltaTime << "\n";
}

void Game::render()
{
	m_pWindow->draw( m_player );

	//m_pWindow->draw( m_circleShape1 );
	//m_pWindow->draw( m_circleShape2 );

}

