#include <SFML/Graphics.hpp>
#include <string>
#include "Grid.h"
#include "LinkedList.h"
#include "Sprite.h"
#include "EnvironmentObject.h"
#pragma once

class Game
{

private:

	sf::RenderWindow m_window;
	sf::VideoMode m_videoMode;
	std::string m_windowString;
	sf::Time m_TimePerFrame = sf::seconds(1.f / 60);
	void handleEvents();
	void update(sf::Time deltaTime);
	void render();
	Grid m_grid;
	Sprite m_player;
	Sprite m_enemy;
	LinkedList m_particlelist;
	Particle **m_particleArray = new Particle*[10];
	EnvironmentObject m_object1;
	//particleNode* createNewParticleNode();
	int m_numOfSpawnedParticles;
	static Game* m_instance;
	Collideable m_allColliders[3];


public:

	Game();
	~Game();
	void run();

	sf::RenderWindow& getWindow();
	static Game* getInstance();
	int getnumSParticles();
	void setnumSParticles(int num);
	std::string checkCollision();
};


