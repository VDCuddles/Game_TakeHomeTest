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
	Particle m_particle;
	//Particle m_particle2;
	Sprite m_player;
	Sprite m_enemy;
	LinkedList m_particlelist;
	Particle **m_particleArray = new Particle*[10];
	EnvironmentObject m_object1;
	//void initArrayofParticles();
	//particleNode* createNewParticleNode();
	bool particleInitialised;
	static Game* m_instance;


public:

	Game();
	~Game();
	void run();

	sf::RenderWindow& getWindow();
	static Game* getInstance();
	//struct particleNode;
};


