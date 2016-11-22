#include <SFML/Graphics.hpp>
#include <string>
#include "Grid.h"
#include "Particle.h"
#pragma once

class Game
{

private:

	sf::RenderWindow m_window;
	sf::VideoMode m_videoMode;
	std::string m_windowString;
	sf::Time TimePerFrame = sf::seconds(1.f / 60);
	void handleEvents();
	void update(sf::Time deltaTime);
	void render();
	Grid grid;
	Particle particle;


public:

	Game();
	~Game();
	void run();

};


