#include "InputHandler.hpp"
#include <iostream>


InputHandler::InputHandler(sf::RenderWindow* w, Game* pg) {
	this->pWindow = w;
	this->pGame = pg; // This is the player that will be moved etc.
}

void InputHandler::processEvents() {
	sf::Event event;

	if (pGame->gameOver == false) {

		while (this->pWindow->pollEvent(event)) {



			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					//Turn left, but only when going forward or backward
					if (pGame->playerDirection == GameConstants::PlayerDirection::Forward || pGame->playerDirection == GameConstants::PlayerDirection::Backward)
						pGame->playerDirection = GameConstants::PlayerDirection::Left;
					break;
				case sf::Keyboard::D:
					//Turn right, but only when going forward or backward
					if (pGame->playerDirection == GameConstants::PlayerDirection::Forward || pGame->playerDirection == GameConstants::PlayerDirection::Backward)
						pGame->playerDirection = GameConstants::PlayerDirection::Right;
					break;
				case sf::Keyboard::W:
					//Turn forward, but only when going right or left
					if (pGame->playerDirection == GameConstants::PlayerDirection::Right || pGame->playerDirection == GameConstants::PlayerDirection::Left)
						pGame->playerDirection = GameConstants::PlayerDirection::Forward;
					break;
				case sf::Keyboard::S:
					//Turn backward, but only when going right or left
					if (pGame->playerDirection == GameConstants::PlayerDirection::Right || pGame->playerDirection == GameConstants::PlayerDirection::Left)
						pGame->playerDirection = GameConstants::PlayerDirection::Backward;
					break;
				default:
					break;
				}
			}

			// Close window: exit
			if (event.type == sf::Event::Closed) {
				pWindow->close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				pWindow->close();
			}
		}
	}
	else {

		while (this->pWindow->pollEvent(event)) {



			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				pGame->StartNewGame();
			}

			// Close window: exit
			if (event.type == sf::Event::Closed) {
				pWindow->close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				pWindow->close();
			}

		}
	}
}