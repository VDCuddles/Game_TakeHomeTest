#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#pragma once

class EnvironmentObject
{

private:

	sf::Texture m_texture;
	sf::Vector2f m_position;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;


public:

	EnvironmentObject();
	void loadTexture(std::string directory);
	void drawObject(sf::RenderWindow *window);
	void setPosition(sf::Vector2f position);
	void setTextureRect(sf::IntRect rect);
	void setIntRect(int left, int top, int width, int height);
	void setTexture();

};
