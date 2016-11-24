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
	NONE
};

class Sprite
{

private:

	sf::Texture m_texture;
	sf::Vector2f m_position;
	sf::Vector2f m_enemyPosition;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;
	int m_row;
	int m_frame;
	int m_frameMax = 4;
	int m_frameDirection;
	Direction m_facing;



public:

	Sprite();
	//Sprite::Sprite(CharacterType charatype);
	void drawSprite(sf::RenderWindow *window);
	void animate(Direction dir);
	void updatePosition(Direction dir, sf::Vector2f position);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void loadSheet(CharacterType charac);
	void setFacing(Direction dir);
	Direction getFacing();
	void setTextureRect(sf::IntRect rect);
	void setIntRect(int left, int top, int width, int height);
	void setTexture();

};


