#include "Particle.h"


Particle::Particle() {

	particle.setRadius(10);
	particle.setFillColor(sf::Color::Red);
	particle.setOrigin(10, 10);

	//float width = (float)sf::VideoMode::getDesktopMode().width;
	//float height = (float)sf::VideoMode::getDesktopMode().height;
	particle.setPosition((256),(256));
	speed = 0.15;
	deltaX = 1;
	deltaY = 0.8;
	hasAscended = false;

}

void Particle::Update() {


	deltaY -= 0.0002;

	newposX = particle.getPosition().x;
	newposY = particle.getPosition().y - (speed * deltaY);
	particle.setPosition(newposX, newposY);

}

void Particle::drawParticle(sf::RenderWindow *window) {

	window->draw(particle);
}
