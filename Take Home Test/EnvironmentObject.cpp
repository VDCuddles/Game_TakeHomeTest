#include "EnvironmentObject.h"


EnvironmentObject::EnvironmentObject() {

	//m_textureRect.left = 0;
	//m_textureRect.top = 0;
	//m_textureRect.width = 0;
	//m_textureRect.height = 0;

	//m_position = (sf::Vector2f(200, 200));
	//loadTexture();

	//m_sprite.updatePosition(m_position);
	//m_sprite.setTextureRect(m_textureRect);
	//m_sprite.setTexture(m_texture);
}

void EnvironmentObject::drawObject(sf::RenderWindow *window) {

	window->draw(m_sprite);
}

void EnvironmentObject::loadTexture(std::string directory) {
	if (!m_texture.loadFromFile(directory))
	{
		std::cout << "Error loading resource sprite.png" << std::endl;
	}
}

void EnvironmentObject::setPosition(sf::Vector2f position) {
	m_sprite.setPosition(position);
}

void EnvironmentObject::setIntRect(int left, int top, int width, int height) {
	sf::IntRect rect;
	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height = height;
	m_sprite.setTextureRect(rect);

}

void EnvironmentObject::setTextureRect(sf::IntRect rect) {
	m_textureRect = rect;
}

void EnvironmentObject::setTexture() {
	m_sprite.setTexture(m_texture);
}

//collision

float EnvironmentObject::getCollisionBounds() {
	float bounds = m_collideable.getCollisionBounds();
	return bounds;
}

sf::Vector2f EnvironmentObject::getOrigin() {
	sf::Vector2f origin = m_sprite.getOrigin();
	return origin;
}

void EnvironmentObject::setOrigin(sf::Vector2f origin) {
	m_sprite.setOrigin(origin);
}

void EnvironmentObject::setColliderOrigin(sf::Vector2f origin) {
	m_collideable.setOrigin(origin);
}

void EnvironmentObject::setColliderPosition(sf::Vector2f position) {
	m_collideable.setPosition(position);
}


void EnvironmentObject::setColliderRadius(float radius) {
	m_collideable.setRadius(radius);
}

void EnvironmentObject::drawCollider(sf::RenderWindow *window) {
	m_collideable.drawBounds(window);
}