#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {

	if (!m_characterSprite.loadFromFile("Resources/sprite.png"))
	{
		std::cout << "Error loading resource sprite.png"<< std::endl;
	}
	m_textureRect.left = 0;
	m_textureRect.top = 0;
	m_textureRect.width = 25;
	m_textureRect.height = 34;

	m_position = (sf::Vector2f(100, 100));

	m_sprite.setPosition(m_position);
	m_sprite.setTextureRect(m_textureRect);
	m_sprite.setTexture(m_characterSprite);

}

void Sprite::drawSprite(sf::RenderWindow *window) {
	window->draw(m_sprite);
}

void Sprite::update() {

}