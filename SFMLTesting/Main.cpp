/*
Main.cpp
Author: PotatoSauceVFX - 2017
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace sf;
using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 720;

Vector2i mousePos = Mouse::getPosition();

float yOffset;

int main() {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "My Window");
	window.setFramerateLimit(60.0);

	CircleShape shapes[WIDTH];

	for (int i = 0; i < (sizeof(shapes) / sizeof(*shapes)); i++) {
		shapes[i] = CircleShape(1.0f);
	}
	for (int i = 0; i < (sizeof(shapes) / sizeof(*shapes)); i++) {
		shapes[i].setFillColor(Color(0, 233, 0, 255));
	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Make yPos calculations
		

		// Setting positions
		for (int i = 0; i < (sizeof(shapes) / sizeof(*shapes)); i++) {
			yOffset = (sin(0.03*i))*(HEIGHT / 3);
			shapes[i].setPosition(i, ((HEIGHT / 2.0) - 5.0) + yOffset);
		}
		//shape.setPosition(mouseX -5.0, ((HEIGHT / 2.0)-5.0)+yOffset);
		//shape2.setPosition(mouseX - 5.0, ((HEIGHT / 2.0) - 5.0));


		
		window.clear();
		for (int i = 0; i < (sizeof(shapes) / sizeof(*shapes)); i++) {
			window.draw(shapes[i]);
		}
		window.display();
	}

	return 0;
}