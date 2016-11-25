#include "Collideable.h"

Collideable::Collideable() {
	m_collisionBounds.setFillColor(sf::Color(255, 255, 255, 55));
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

sf::Vector2f Collideable::getPosition() {
	sf::Vector2f position = m_collisionBounds.getPosition();
	return position;
}

void Collideable::setPosition(sf::Vector2f position) {
	m_collisionBounds.setPosition(position);
}

float Collideable::getCollisionBounds() {
	float bounds = m_collisionBounds.getRadius()*1.5;
	return bounds;
}

sf::Vector2f Collideable::getTileLocation() {
	sf::Vector2f currentloc = m_collisionBounds.getPosition();
	currentloc.x /= 12;
	currentloc.y /= 12;
	return currentloc;
}
