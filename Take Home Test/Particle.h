#include <SFML/Graphics.hpp>
#pragma once

class Particle
{

private:

	sf::CircleShape particle;
	sf::Vector2f middlePosition;
	float speed;
	float deltaX;
	float deltaY;
	float newposX;
	float newposY;
	bool hasAscended;

public:

	Particle();
	void update();
	void drawParticle(sf::RenderWindow *window);

};


