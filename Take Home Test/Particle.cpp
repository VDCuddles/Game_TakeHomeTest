#include "Particle.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Particle::Particle() {

	beenInitialised = false;

	m_life = 100;
	m_alpha = 255 * (m_life);
	m_fillColor = sf::Color(0, 255, 0, m_alpha);

	m_particle.setRadius(15);
	m_particle.setFillColor(m_fillColor);
	m_particle.setOrigin(15, 15);
	m_particle.setPosition((384),(384));

	m_speed = 10;
	m_deltaX = 0.8;
	m_deltaY = 0.8;

	srand(time((time_t)NULL));
	m_horizonttalOffset = rand() % (10);
	if (m_horizonttalOffset > 5) {
		m_horizonttalOffset *= -1;
	}
	m_horizonttalOffset /= 4;
}

void Particle::update() {


	m_life -= 0.5;
	m_alpha = 255 * (m_life/100);
	m_fillColor = sf::Color(0, 255, 0, m_alpha);
	m_particle.setFillColor(m_fillColor);

	m_deltaY -= 0.01;
	m_newposX = m_particle.getPosition().x + (m_horizonttalOffset);
	m_newposY = m_particle.getPosition().y - (m_speed * m_deltaY);
	m_particle.setPosition(m_newposX, m_newposY);

}

void Particle::drawParticle(sf::RenderWindow *window) {

	window->draw(m_particle);
}

bool Particle::initialisehOffset() {
	if (beenInitialised == false)
	{
		srand(time((time_t)NULL));
		m_horizonttalOffset = rand() % (10);
		if (m_horizonttalOffset > 5) {
			m_horizonttalOffset *= -1;
		}
		m_horizonttalOffset /= 4;
		beenInitialised = true;
		return true;
	}
	else {
		return false;
	}
}
