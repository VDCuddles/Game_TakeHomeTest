#include "Grid.h"


Grid::Grid() {

	m_lines.setPrimitiveType(sf::Lines);
	m_lines.resize(2 * (64 + 64 + 2));
	for (int i = 0; i < 64; i++) {
		float iX = (float)(i * 12);
		m_lines[2 * i] = sf::Vector2f(iX, 0);
		m_lines[2 * i + 1] = sf::Vector2f(iX, 768);
	}
	for (int i = 0; i < 64; i++) {
		float iY = (float)(i * 12);
		m_lines[2 * 64 + 2 * i] = sf::Vector2f(0, iY);
		m_lines[2 * 64 + 2 * i + 1] = sf::Vector2f(768, iY);
	}
}

void Grid::drawGrid(sf::RenderWindow *window) {

	window->draw(m_lines);
}