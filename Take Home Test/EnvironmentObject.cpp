#include "EnvironmentObject.h"


EnvironmentObject::EnvironmentObject() {

	//m_textureRect.left = 0;
	//m_textureRect.top = 0;
	//m_textureRect.width = 0;
	//m_textureRect.height = 0;

	//m_position = (sf::Vector2f(200, 200));
	//loadTexture();

	//m_sprite.setPosition(m_position);
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
