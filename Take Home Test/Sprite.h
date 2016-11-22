#include <SFML/Graphics.hpp>
#pragma once

enum CharacterType
{
	ENEMY,
	PLAYER
};

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class Sprite
{

private:

	sf::Texture m_characterSprite;
	sf::Vector2f m_position;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;



public:

	Sprite();
	void drawSprite(sf::RenderWindow *window);
	void update();
	void setPosition(Direction dir);
	void loadSheet(CharacterType charac);

};


