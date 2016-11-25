#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Collideable.h"
#pragma once

class EnvironmentObject
{

private:

	sf::Texture m_texture;
	sf::Vector2f m_position;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;
	//collision
	bool m_isColliding;
	Collideable m_collideable;


public:

	EnvironmentObject();
	void loadTexture(std::string directory);
	void drawObject(sf::RenderWindow *window);
	void setPosition(sf::Vector2f position);
	void setTextureRect(sf::IntRect rect);
	void setIntRect(int left, int top, int width, int height);
	void setTexture();
	//collision
	float getCollisionBounds();
	void setOrigin(sf::Vector2f origin);
	sf::Vector2f getOrigin();
	void setColliderOrigin(sf::Vector2f origin);
	void setColliderPosition(sf::Vector2f position);
	void setColliderRadius(float radius);
	void drawCollider(sf::RenderWindow *window);

};
