#include "Grid.h"


Grid::Grid() {

	lines.setPrimitiveType(sf::Lines);
	lines.resize(2 * (64 + 64 + 2));
	for (int i = 0; i < 64; i++) {
		float iX = (float)(i * 12);
		lines[2 * i] = sf::Vector2f(iX, 0);
		lines[2 * i + 1] = sf::Vector2f(iX, 768);
	}
	for (int i = 0; i < 64; i++) {
		float iY = (float)(i * 12);
		lines[2 * 64 + 2 * i] = sf::Vector2f(0, iY);
		lines[2 * 64 + 2 * i + 1] = sf::Vector2f(768, iY);
	}
}

void Grid::drawGrid(sf::RenderWindow *window) {

	window->draw(lines);
}