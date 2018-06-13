// BalanceUI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>


int main()
{
	// Create the main window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	const int height = 400;
	const int width = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "Balance", sf::Style::Default, settings);

	window.setFramerateLimit(60);
	int x = -200;
	int dx = -3;
	const int y = -100;
	const float radius = 10;
	//const  sf::Vector2u  rect_d = (200, 5);

	sf::CircleShape circle{ radius };
	sf::RectangleShape rect{sf::Vector2f(50,5) };
	int angle = 0;
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the string
		
//		rect.setOrigin(-20, y-20);
//		sf::Transform rotator;
//		rotator.rotate(beam:angle() / pi * 180, x, y);
		//rect.rotate(10);

		rect.setOrigin(-200, -100);
		sf::Transform rotator;
		rotator.rotate(angle++, 225, 102.5);
		window.draw(rect, rotator);



		circle.setOrigin(x, y);
		if(x > 0 || x < -(width - 2*radius))
		{
			dx = -dx;
		}
		x += dx;

		//window.draw(rect);
		window.draw(circle);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}

