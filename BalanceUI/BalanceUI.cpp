// BalanceUI.cpp : Defines the entry point for the console application.
//
// Objekte -> linke obere ecke ist der Platzierpunkt
//
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
	float x = -290;
	int dx = -3;
	float y = -180;
	const float radius = 10;
	float set = 1; //only for testing purpose, will be swapped with setangle from controller

	sf::CircleShape circle{ radius };
	sf::RectangleShape rect{sf::Vector2f(400,5) };
	int angle = 1;

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
		

		rect.setOrigin(-100, -200);
		sf::Transform rotator;

		// if else-if only for testing purpose
		if (x > -95) {
			set = +1; // angle ++ for circle rotate
		}
		else if (x < -485) {
			set = -1;
		}
		rotator.rotate((set), 300, 205); //change angle to controller.getangle from controller 

		circle.setOrigin(x, y);
	
		//change here the new x value according to the current velocity
		if(x > -90 || x < -490)
		{
			dx = -dx;
		}
		x += dx;

		window.draw(rect, rotator);
		window.draw(circle, rotator);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}

