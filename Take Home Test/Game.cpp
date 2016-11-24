#include "Game.h"

Game::Game() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_window.create(sf::VideoMode(sf::VideoMode(768,768)), "Take Home Test", sf::Style::Default, settings);
	//Sprite* m_enemy = new Sprite(ENEMY);

	//Sprite m_player(PLAYER);
	//Sprite m_enemy(ENEMY);
	m_player.loadSheet(PLAYER);
	m_player.setPosition(NONE, sf::Vector2f(100, 100));

	m_enemy.loadSheet(ENEMY);
	m_enemy.setPosition(NONE, sf::Vector2f (500,500));

	m_object1.setIntRect(392, 383, 38, 96);
	m_object1.loadTexture("Resources/tileset_desert.png"); 
	m_object1.setPosition(sf::Vector2f(300, 300));
	m_object1.setTexture();

	Particle p1;
	Particle p2;
	m_particlelist.addParticleToList(p1);
	m_particlelist.addParticleToList(p2);
	
}

Game::~Game()
{
	m_window.close();
}

void Game::handleEvents() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player.setPosition(UP, m_player.getPosition());
		m_player.setFacing(UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.setPosition(DOWN, m_player.getPosition());
		m_player.setFacing(DOWN);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.setPosition(LEFT, m_player.getPosition());
		m_player.setFacing(LEFT);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.setPosition(RIGHT, m_player.getPosition());
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

}

void Game::render() {
	m_window.clear();
	m_grid.drawGrid(&m_window);
	m_particle.update();
	m_particle.drawParticle(&m_window);
	m_particle2.update();
	m_particle2.drawParticle(&m_window);
	m_object1.drawObject(&m_window);
	m_player.animate(m_player.getFacing());
	m_player.drawSprite(&m_window);
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


//code here references http://stackoverflow.com/questions/21420772/array-of-linked-lists-c

//struct Game::particleNode {
//	Particle nodeParticle;
//	particleNode *next;
//};
//
//Game::particleNode* createNewParticleNode{
//
//}
//
//void Game::initArrayofParticles() {
//	nodeArray = new *particleNode[];
//}