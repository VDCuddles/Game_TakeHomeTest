#include <SFML/Graphics.hpp>
#pragma once

class Grid
{

private:

	sf::VertexArray lines;

public:

	Grid();
	
	void drawGrid(sf::RenderWindow *window);

};


