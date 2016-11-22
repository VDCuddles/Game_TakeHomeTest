#include <SFML/Graphics.hpp>
#pragma once

class Grid
{

private:

	sf::VertexArray m_lines;

public:

	Grid();
	
	void drawGrid(sf::RenderWindow *window);

};


