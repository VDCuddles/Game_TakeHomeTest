#include "Collideable.h"

Collideable::Collideable() {
	m_collisionBounds.setFillColor(sf::Color(255,0,0,55));
}

void Collideable::drawBounds(sf::RenderWindow *window) {
	window->draw(m_collisionBounds);
}

void Collideable::setRadius(float radius) {
	m_collisionBounds.setRadius(radius);
}

void Collideable::setOrigin(sf::Vector2f origin) {
	m_collisionBounds.setOrigin(origin);
}

void Collideable::setPosition(sf::Vector2f position) {
	m_collisionBounds.setPosition(position);
}

float Collideable::getCollisionBounds() {
	float bounds = m_collisionBounds.getRadius();
	return bounds;
}
