#include <SFML/Graphics.hpp>
#include <map>
#pragma once

class Grid
{

private:

	sf::VertexArray m_lines;
	static const int ROW_COUNT = 64;
	static const int COLUMN_COUNT = 64;

public:

	Grid();
	static const int m_map[ROW_COUNT][COLUMN_COUNT];
	void drawGrid(sf::RenderWindow *window);
	//int getTileType(int x, int y);

	enum Tile {

		TileOpen = 1,
		TileClosed = 2,

	};

};


