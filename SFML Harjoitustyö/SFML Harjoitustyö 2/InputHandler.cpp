#include "InputHandler.hpp"
#include <iostream>


InputHandler::InputHandler(sf::RenderWindow* w, Game* pg) {
	this->pWindow = w;
	this->pGame = pg; // This is the player that will be moved etc.
}

void InputHandler::processEvents() {
	sf::Event event;

	while (this->pWindow->pollEvent(event)) {

		

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::A:
				//go left
				break;
			case sf::Keyboard::D:
				//go right
				break;
			case sf::Keyboard::W:
				//go forward
				break;
			case sf::Keyboard::S:
				//go backward
				break;
			default:
				break;
			}
		}
	}
}