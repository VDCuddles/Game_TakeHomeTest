#include "Game.h"

Game* Game::m_instance = 0;
Game::Game() {

	m_instance = this;
	m_numOfSpawnedParticles = 0;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_window.create(sf::VideoMode(sf::VideoMode(768,768)), "Take Home Test", sf::Style::Default, settings);

	m_player.setIntRect(0, 0, 24, 36);
	m_player.setOrigin(sf::Vector2f( 12, 13));
	m_player.loadSheet(PLAYER);
	m_player.setPosition(sf::Vector2f(100, 100));
	m_player.setTexture();
	m_player.setColliderRadius(16);
	m_player.setColliderOrigin(sf::Vector2f(16, 12));
	m_player.setColliderPosition(sf::Vector2f(100, 100));

	m_enemy.setIntRect(0, 0, 24, 36);
	m_enemy.setOrigin(sf::Vector2f(12, 13));
	m_enemy.loadSheet(ENEMY);
	m_enemy.setPosition(sf::Vector2f (500,500));
	m_enemy.setTexture();
	m_enemy.setColliderRadius(16);
	m_enemy.setColliderOrigin(sf::Vector2f(16, 12));
	m_enemy.setColliderPosition(sf::Vector2f(500, 500));

	m_object1.setIntRect(392, 383, 38, 96);
	m_object1.setOrigin(sf::Vector2f(19, 48));
	m_object1.loadTexture("Resources/tileset_desert.png");
	m_object1.setPosition(sf::Vector2f(384, 415));
	m_object1.setTexture();
	m_object1.setColliderRadius(19);
	m_object1.setColliderOrigin(sf::Vector2f(19, 19));
	m_object1.setColliderPosition(sf::Vector2f(390, 440));

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
		m_player.setColliderPosition(m_player.getPosition());
		m_player.setFacing(UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.updatePosition(DOWN, m_player.getPosition());
		m_player.setColliderPosition(m_player.getPosition());
		m_player.setFacing(DOWN);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.updatePosition(LEFT, m_player.getPosition());
		m_player.setColliderPosition(m_player.getPosition());
		m_player.setFacing(LEFT);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.updatePosition(RIGHT, m_player.getPosition());
		m_player.setColliderPosition(m_player.getPosition());
		m_player.setFacing(RIGHT);

	}
	if (!sf::Keyboard::isKeyPressed) 
	{
		m_player.setColliderPosition(m_player.getPosition());
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


	m_allColliders[0] = m_player.getCollider();
	m_allColliders[1] = m_enemy.getCollider();
	m_allColliders[2] = m_object1.getCollider();

	checkCollision();

	if (m_numOfSpawnedParticles < 10) {
			m_particleArray[m_numOfSpawnedParticles] = new Particle();
			setnumSParticles(getnumSParticles()+1);
	}


	m_enemy.chase(m_player.getPosition());
	m_player.animate(m_player.getFacing());
	m_enemy.animate(m_enemy.getFacing());
	for (int i = 0; i < getnumSParticles(); i++) {
		m_particleArray[i]->update();
	}

}

void Game::render() {
	m_window.clear();
	for (int i = 0; i < getnumSParticles(); i++) {
		m_particleArray[i]->drawParticle(&m_window);
	}

	for (int i = 0; i < 3; i++) {
		m_allColliders[i].drawBounds(&m_window);
	}
	m_grid.drawGrid(&m_window);
	m_player.drawSprite(&m_window);
	m_enemy.drawSprite(&m_window);
	m_object1.drawObject(&m_window);


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

int Game::getnumSParticles() {
	return m_numOfSpawnedParticles;
}
void Game::setnumSParticles(int num) {
	m_numOfSpawnedParticles = num;
}

std::string Game::checkCollision() {

	sf::Vector2f playerPos;
	sf::Vector2f enemyPos;
	float characterbounds;
	sf::Vector2f object1Pos;
	std::string output;

	playerPos = m_allColliders[0].getPosition();
	enemyPos = m_allColliders[1].getPosition();
	object1Pos = m_allColliders[2].getPosition();
	characterbounds = m_allColliders[0].getCollisionBounds();

	if ((abs(playerPos.x - enemyPos.x) < characterbounds)
		&& (abs(playerPos.y - enemyPos.y) < characterbounds))//range for hit registration on player
	{
		//if (attackTimer.getElapsedTime().asSeconds() > 1)//only allow 1 attack every second per enemy
		//{
		//	//remove / comment next line for godmode
		//	Game::instance()->getWorld().getEntities()[0]->applyDamage(10);
		//	attackTimer.restart();//restart the timer for next attack
		//}

		std::cout << "01" << std::endl;
		return "01";
	}

	else {
		return "00";
	}

}