#include <SFML/Graphics.hpp>
#pragma once

class Collideable
{

private:

	sf::CircleShape m_collisionBounds;


public:

	Collideable();
	void setPosition(sf::Vector2f position);
	float getCollisionBounds();
	void setOrigin(sf::Vector2f origin);
	void setRadius(float radius);
	void drawBounds(sf::RenderWindow *window);


};

