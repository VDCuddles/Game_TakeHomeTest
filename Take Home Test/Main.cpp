#include <SFML/Graphics.hpp>
#include <string>

int main()
{
 
	sf::RenderWindow window(sf::VideoMode(512, 512), "Take Home Test");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	sf::VertexArray horLines(sf::Lines, 2*(64 + 64 + 2));

	//for (int i = 1; i <= 64; i++) {
	//	horLines[i-1].position.x = 0;
	//	horLines[i-1].position.y = ((i-1)*8);
	//	horLines[i].position.x = 600;
	//	horLines[i].position.y = ((i - 1) * 8);
	//}

	for (int i = 0; i < 64; i++) {
		float iX = (float)(i*8);
		horLines[2 * i] = sf::Vector2f(iX, 0);
		horLines[2 * i + 1] = sf::Vector2f(iX, 600);
	}

	for (int i = 0; i < 64; i++) {
		float iY = (float)(i*8);
		horLines[2 * 64 + 2 * i] = sf::Vector2f(0, iY);
		horLines[2 * 64 + 2 * i + 1] = sf::Vector2f(800, iY);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(horLines);
		window.display();
	}

	return 0;
}