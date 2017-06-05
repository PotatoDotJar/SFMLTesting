/*
Main.cpp
Author: PotatoSauceVFX - 2017
*/
#include <SFML/Graphics.hpp>

using namespace sf;

const int WIDTH = 1280;
const int HEIGHT = 720;

int main()
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}