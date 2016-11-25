#include <SFML/Graphics.hpp>
#include "Collideable.h"
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

	Direction m_facing;
	sf::Texture m_texture;
	sf::Vector2f m_position;
	sf::Vector2f m_enemyPosition;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;
	int m_row;
	int m_frame;
	int m_frameMax = 4;
	int m_frameDirection;
	//collision
	bool m_isColliding;
	Collideable m_collideable;

public:

	Sprite();
	Direction getFacing();
	sf::Vector2f getPosition();
	void drawSprite(sf::RenderWindow *window);
	void animate(Direction dir);
	void updatePosition(Direction dir, sf::Vector2f position);
	void setPosition(sf::Vector2f position);
	void loadSheet(CharacterType charac);
	void setFacing(Direction dir);
	void setTextureRect(sf::IntRect rect);
	void setIntRect(int left, int top, int width, int height);
	void setTexture();
	void chase(sf::Vector2f target);
	//collision
	float getCollisionBounds();
	void setOrigin(sf::Vector2f origin);
	sf::Vector2f getOrigin();
	void setColliderOrigin(sf::Vector2f origin);
	void setColliderPosition(sf::Vector2f position);
	void setColliderRadius(float radius);
	void drawCollider(sf::RenderWindow *window);
	Collideable getCollider();
	sf::Vector2i getColliderTileLocation();
};


