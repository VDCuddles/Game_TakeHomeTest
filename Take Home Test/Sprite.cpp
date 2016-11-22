#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {

	loadSheet(PLAYER);
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

void Sprite::setPosition(Direction dir) {
	if (dir == UP) {
		m_position.y -= 1;
		m_sprite.setPosition(m_position);
	}
	if (dir == DOWN) {
		m_position.y += 1;
		m_sprite.setPosition(m_position);
	}
	if (dir == LEFT) {
		m_position.x -= 1;
		m_sprite.setPosition(m_position);
	}
	if (dir == RIGHT) {
		m_position.x += 1;
		m_sprite.setPosition(m_position);
	}

}

void Sprite::loadSheet(CharacterType charac){

	if (charac == PLAYER)
	{
		if (!m_characterSprite.loadFromFile("Resources/player.png"))
		{
			std::cout << "Error loading resource sprite.png" << std::endl;
		}
	}
	if (charac == ENEMY)
	{
		if (!m_characterSprite.loadFromFile("Resources/enemy.png"))
		{
			std::cout << "Error loading resource sprite.png" << std::endl;
		}
	}
}