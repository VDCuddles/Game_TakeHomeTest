#include "Game.h"

Game::Game() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_window.create(sf::VideoMode(sf::VideoMode(768,768)), "Take Home Test", sf::Style::Default, settings);

}

Game::~Game()
{
	m_window.close();
}

void Game::handleEvents() {

}

void Game::update(sf::Time deltaTime) {

}

void Game::render() {
	m_window.clear();
	grid.drawGrid(&m_window);
	particle.update();
	particle.drawParticle(&m_window);
	m_window.display();
}

void Game::run(){
	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		handleEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleEvents();
			update(TimePerFrame);
		}
		render();
	}
	
}