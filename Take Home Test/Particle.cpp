#include "Particle.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Particle::Particle() {

	//beenInitialised = false;

	m_life = 100;
	m_alpha = 255 * (m_life);
	m_fillColor = sf::Color(255, 181, 70, m_alpha);

	m_particle.setRadius(15);
	m_particle.setFillColor(m_fillColor);
	m_particle.setOrigin(15, 15);
	m_particle.setPosition((384),(384));

	m_speed = 10;
	m_deltaX = 0.8;
	m_deltaY = 0.8;

	srand(time((time_t)NULL));
	//m_horizonttalOffset = rand() % (10);
	//if (m_horizonttalOffset > 5) {
	//	m_horizonttalOffset *= -1;
	//}
	//m_horizonttalOffset /= 4;
}

void Particle::update() {

	srand(time((time_t)NULL));
	m_horizonttalOffset = rand() % (10);
	if (m_horizonttalOffset > 5) {
		m_horizonttalOffset *= -1;
	}
	m_horizonttalOffset /= 2;

	if (m_particle.getPosition().y > 768) {
		m_particle.setPosition(384, 384);
		m_life = 100;
		m_deltaY = 0.8;
	}


	m_life -= 0.5;
	m_alpha = 255 * (m_life/100);
	m_fillColor = sf::Color(255, (120 + (rand() % (50))), (20 + (rand() % (50))), m_alpha);
	m_particle.setFillColor(m_fillColor);

	m_deltaY -= 0.01;
	m_newposX = m_particle.getPosition().x + (m_horizonttalOffset);
	m_newposY = m_particle.getPosition().y - (m_speed * m_deltaY);
	m_particle.setPosition(m_newposX, m_newposY);

}

void Particle::update2() {

	m_horizonttalOffset = rand() % (10);
	if (m_horizonttalOffset > 5) {
		m_horizonttalOffset *= -1;
	}
	m_horizonttalOffset /= 2;

	if (m_particle.getPosition().y > 768) {
		m_particle.setPosition(384, 384);
		m_life = 100;
		m_deltaY = 0.8;
	}


	m_life -= 0.5;
	m_alpha = 255 * (m_life / 100);
	m_fillColor = sf::Color((70 + (rand() % (50))), (0 + (rand() % (50))), (180 + (rand() % (50))), m_alpha);
	m_particle.setFillColor(m_fillColor);

	m_deltaY -= 0.01;
	m_newposX = m_particle.getPosition().x + (m_horizonttalOffset);
	m_newposY = m_particle.getPosition().y - (m_speed * m_deltaY);
	m_particle.setPosition(m_newposX, m_newposY);

}

void Particle::drawParticle(sf::RenderWindow *window) {

	window->draw(m_particle);
}