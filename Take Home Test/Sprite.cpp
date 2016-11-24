#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {

	//loadSheet(PLAYER);
	m_textureRect.left = 0;
	m_textureRect.top = 0;
	m_textureRect.width = 24;
	m_textureRect.height = 36;

	//m_position = (sf::Vector2f(100, 100));

	m_sprite.setPosition(m_position);
	m_sprite.setTextureRect(m_textureRect);
	m_sprite.setTexture(m_texture);

}

//Sprite::Sprite(CharacterType charatype) {

//	loadSheet(charatype);
//	m_textureRect.left = 0;
//	m_textureRect.top = 0;
//	m_textureRect.width = 24;
//	m_textureRect.height = 36;
//
//	m_position = (sf::Vector2f(500, 500));
//
//	m_sprite.updatePosition(m_enemyPosition);
//	m_sprite.setTextureRect(m_textureRect);
//	m_sprite.setTexture(m_texture);
//
//	if (charatype == PLAYER)
//	{
//		m_position = (sf::Vector2f(100, 100));
//	}
//
//}

void Sprite::drawSprite(sf::RenderWindow *window) {
	window->draw(m_sprite);
}

void Sprite::animate(Direction dir) {

	if (dir != NONE)
	{
		if (m_frame < 0) {
			m_frame = m_frameMax - 1;
		}
		else if (m_frame == m_frameMax) {
			m_frame = 1;
		}
	}

	if (dir == DOWN) {
		m_sprite.setTextureRect(sf::IntRect(m_frame * m_textureRect.width, 0, m_textureRect.width, m_textureRect.height));
	}
	if (dir == UP) {
		m_sprite.setTextureRect(sf::IntRect(m_frame * m_textureRect.width, m_textureRect.height, m_textureRect.width, m_textureRect.height));
	}
	if (dir == LEFT) {
		m_sprite.setTextureRect(sf::IntRect(m_frame * m_textureRect.width, m_textureRect.height * 2, m_textureRect.width, m_textureRect.height));
	}
	if (dir == RIGHT) {
		m_sprite.setTextureRect(sf::IntRect(m_frame * m_textureRect.width, m_textureRect.height * 3, m_textureRect.width, m_textureRect.height));
	}

	m_frame++;


}

void Sprite::updatePosition(Direction dir, sf::Vector2f position){
	if (dir == UP) {
		m_position.y -= 1;
		m_sprite.setPosition(position);
	}
	if (dir == DOWN) {
		m_position.y += 1;
		m_sprite.setPosition(position);
	}
	if (dir == LEFT) {
		m_position.x -= 1;
		m_sprite.setPosition(position);
	}
	if (dir == RIGHT) {
		m_position.x += 1;
		m_sprite.setPosition(position);
	}

}

sf::Vector2f Sprite::getPosition() {
	return m_position;
}

void Sprite::setPosition(sf::Vector2f position) {
	m_position = position;
	m_sprite.setPosition(position);
}

void Sprite::loadSheet(CharacterType charac){

	if (charac == PLAYER)
	{
		if (!m_texture.loadFromFile("Resources/player.png"))
		{
			std::cout << "Error loading resource sprite.png" << std::endl;
		}
	}
	if (charac == ENEMY)
	{
		if (!m_texture.loadFromFile("Resources/enemy.png"))
		{
			std::cout << "Error loading resource sprite.png" << std::endl;
		}
	}
}


void Sprite::setFacing(Direction dir) {
	m_facing = dir;
}

Direction Sprite::getFacing() {
	return m_facing;
}

void Sprite::setIntRect(int left, int top, int width, int height) {
	sf::IntRect rect;
	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height = height;
	m_sprite.setTextureRect(rect);

}

void Sprite::setTextureRect(sf::IntRect rect) {
	m_textureRect = rect;
}

void Sprite::setTexture() {
	m_sprite.setTexture(m_texture);
}
