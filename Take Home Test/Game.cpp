#include "Game.h"

Game* Game::m_instance = 0;
Game::Game() {

	m_instance = this;
	particleInitialised = false;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_window.create(sf::VideoMode(sf::VideoMode(768,768)), "Take Home Test", sf::Style::Default, settings);

	m_player.setIntRect(0, 0, 24, 36);
	m_player.loadSheet(PLAYER);
	m_player.setPosition(sf::Vector2f(100, 100));
	m_player.setTexture();

	m_enemy.setIntRect(0, 0, 24, 36);
	m_enemy.loadSheet(ENEMY);
	m_enemy.setPosition(sf::Vector2f (500,500));
	m_enemy.setTexture();

	m_object1.setIntRect(392, 383, 38, 96);
	m_object1.loadTexture("Resources/tileset_desert.png"); 
	m_object1.setPosition(sf::Vector2f(300, 300));
	m_object1.setTexture();

	//Particle p1;
	//Particle p2;
	//m_particlelist.addParticleToList(p1);
	//m_particlelist.addParticleToList(p2);
	for (int i = 0; i < 10; i++) {
		m_particleArray[i] = new Particle();
	}
	
}

Game::~Game()
{
	m_window.close();
}

Game* Game::getInstance()
{
	return m_instance;
}

void Game::handleEvents() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player.updatePosition(UP, m_player.getPosition());
		m_player.setFacing(UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.updatePosition(DOWN, m_player.getPosition());
		m_player.setFacing(DOWN);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.updatePosition(LEFT, m_player.getPosition());
		m_player.setFacing(LEFT);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.updatePosition(RIGHT, m_player.getPosition());
		m_player.setFacing(RIGHT);

	}
	if (!sf::Keyboard::isKeyPressed) 
	{
		m_player.setFacing(NONE);

	}

	sf::Event event;
	if (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:

			m_window.close();
			return;
		}
	}
}

void Game::update(sf::Time deltaTime) {
	if (particleInitialised == false) {
		for (int i = 0; i < 10; i++) {
			if (m_particleArray[i]->initialisehOffset() == false){
			m_particleArray[i]->initialisehOffset();
			}
		}
		particleInitialised = true;
	}


	m_enemy.chase(m_player.getPosition());
	m_player.animate(m_player.getFacing());
	m_enemy.animate(m_enemy.getFacing());
	for (int i = 0; i < 10; i++) {
		m_particleArray[i]->update();
	}
	//m_particle.update();
	//m_particle2.update();
}

void Game::render() {
	m_window.clear();
	for (int i = 0; i < 10; i++) {
		m_particleArray[i]->drawParticle(&m_window);
	}
	m_grid.drawGrid(&m_window);
	//m_particle.drawParticle(&m_window);
	//m_particle2.drawParticle(&m_window);

	m_object1.drawObject(&m_window);
	m_player.drawSprite(&m_window);
	m_enemy.drawSprite(&m_window);
	m_window.display();
}

void Game::run(){
	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		handleEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > m_TimePerFrame)
		{
			timeSinceLastUpdate -= m_TimePerFrame;
			handleEvents();
			update(m_TimePerFrame);
		}
		render();
	}
	
}

sf::RenderWindow& Game::getWindow() {
	return m_window;
}