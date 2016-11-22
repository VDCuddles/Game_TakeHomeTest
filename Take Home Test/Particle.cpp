#include "Particle.h"
#include <cstdlib>
#include <ctime>

Particle::Particle() {

	m_particle.setRadius(15);
	m_particle.setFillColor(sf::Color::Green);
	m_particle.setOrigin(15, 15);

	//float width = (float)sf::VideoMode::getDesktopMode().width;
	//float height = (float)sf::VideoMode::getDesktopMode().height;
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


	m_deltaY -= 0.01;
	m_deltaY -= 0.01;

	m_newposX = m_particle.getPosition().x + (m_horizonttalOffset);
	m_newposY = m_particle.getPosition().y - (m_speed * m_deltaY);
	m_particle.setPosition(m_newposX, m_newposY);

}

void Particle::drawParticle(sf::RenderWindow *window) {

	window->draw(m_particle);
}
