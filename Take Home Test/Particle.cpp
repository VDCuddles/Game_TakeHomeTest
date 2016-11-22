#include "Particle.h"


Particle::Particle() {

	particle.setRadius(15);
	particle.setFillColor(sf::Color::Green);
	particle.setOrigin(15, 15);

	//float width = (float)sf::VideoMode::getDesktopMode().width;
	//float height = (float)sf::VideoMode::getDesktopMode().height;
	particle.setPosition((384),(384));
	speed = 0.55;
	deltaX = 1;
	deltaY = 0.8;
	hasAscended = false;

}

void Particle::update() {


	deltaY -= 0.0005;

	newposX = particle.getPosition().x;
	newposY = particle.getPosition().y - (speed * deltaY);
	particle.setPosition(newposX, newposY);

}

void Particle::drawParticle(sf::RenderWindow *window) {

	window->draw(particle);
}
