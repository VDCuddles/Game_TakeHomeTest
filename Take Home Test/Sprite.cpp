#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {

	m_textureRect.left = 0;
	m_textureRect.top = 0;
	m_textureRect.width = 24;
	m_textureRect.height = 36;


	m_sprite.setPosition(m_position);
	m_sprite.setTextureRect(m_textureRect);
	m_sprite.setTexture(m_texture);

}

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

void Sprite::chase(sf::Vector2f target) {
	if (getPosition().x < target.x) {
		m_position.x += 0.5;
		setFacing(RIGHT);
		setColliderPosition(m_position);
	}
	if (getPosition().y < target.y) {
		m_position.y += 0.5;
		setFacing(DOWN);
		setColliderPosition(m_position);
	}
	if (getPosition().x > target.x){
		m_position.x -= 0.5;
		setFacing(LEFT);
		setColliderPosition(m_position);
	}
	if (getPosition().y > target.y){
		m_position.y -= 0.5;
		setFacing(UP);
		setColliderPosition(m_position);
	}
	setPosition(m_position);

}

//collision

float Sprite::getCollisionBounds() {
	float bounds = m_collideable.getCollisionBounds();
	return bounds;
}

sf::Vector2f Sprite::getOrigin() {
	sf::Vector2f origin = m_sprite.getOrigin();
	return origin;
}

void Sprite::setOrigin(sf::Vector2f origin) {
	m_sprite.setOrigin(origin);
}

void Sprite::setColliderOrigin(sf::Vector2f origin) {
	m_collideable.setOrigin(origin);
}

void Sprite::setColliderPosition(sf::Vector2f position) {
	m_collideable.setPosition(position);
}


void Sprite::setColliderRadius(float radius) {
	m_collideable.setRadius(radius);
}

void Sprite::drawCollider(sf::RenderWindow *window) {
	m_collideable.drawBounds(window);
}