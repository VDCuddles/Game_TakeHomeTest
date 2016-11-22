#include <SFML/Graphics.hpp>
#pragma once

class Particle
{

private:

	sf::CircleShape m_particle;
	sf::Vector2f m_middlePosition;
	float m_speed;
	float m_deltaX;
	float m_deltaY;
	float m_newposX;
	float m_newposY;
	float m_horizonttalOffset;

public:

	Particle();
	void update();
	void drawParticle(sf::RenderWindow *window);

};


