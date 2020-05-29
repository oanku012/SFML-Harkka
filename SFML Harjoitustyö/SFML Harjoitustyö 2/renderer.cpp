#include "renderer.hpp"
//#include "ResourcePath.hpp"
#include <iostream>
#include <cmath>

renderer::renderer(sf::RenderWindow* pw, Game* pg) {
	// Set our render window target
	this->pWindow = pw;

	this->pGame = pg;

	background.setSize(sf::Vector2f(GameConstants::iScreenWidth, GameConstants::iScreenHeight));

	background.setFillColor(sf::Color::Black);

	if (!drive.loadFromFile("Assets/MISTRAL.ttf")) {
		std::cout << "ERROR";
	}

	gameOverText.setFont(drive);

	

	gameOverText.setCharacterSize(24);

	gameOverText.setFillColor(sf::Color::Magenta);

	gameOverText.setPosition(GameConstants::iScreenWidth / 2, GameConstants::iScreenHeight / 2);
}

void renderer::renderGame() 
	{
		

		// Clear the data
		pWindow->clear();

		

		pWindow->draw(background);

		for (int i = 0; i < GameConstants::levelWidth; i++) {
			for (int j = 0; j < GameConstants::levelHeight; j++) {
				if (pGame->gameArea[j][i] == GameConstants::LevelSpace::Snake) {
					sf::RectangleShape newSnakePart(sf::Vector2f(GameConstants::iScreenWidth / GameConstants::levelWidth, GameConstants::iScreenHeight / GameConstants::levelHeight ));
					newSnakePart.setPosition(i * (GameConstants::iScreenWidth / GameConstants::levelWidth), j * (GameConstants::iScreenHeight / GameConstants::levelHeight));
					
					if(pGame->snakeHeadPosX == i && pGame->snakeHeadPosY == j)
						newSnakePart.setFillColor(sf::Color::Red);
					else
						newSnakePart.setFillColor(sf::Color::White);

					pWindow->draw(newSnakePart);
				}
				else if (pGame->gameArea[j][i] == GameConstants::LevelSpace::Food) {
					sf::RectangleShape food(sf::Vector2f(GameConstants::iScreenWidth / GameConstants::levelWidth, GameConstants::iScreenHeight / GameConstants::levelHeight));
					food.setPosition(i * (GameConstants::iScreenWidth / GameConstants::levelWidth), j * (GameConstants::iScreenHeight / GameConstants::levelHeight));
					food.setFillColor(sf::Color::Green);
					pWindow->draw(food);
				}
				
			}
		}

		pWindow->display();
	};

void renderer::renderGameOver() {
	pWindow->clear();

	pWindow->draw(background);

	gameOverText.setString("GAME OVER \n YOUR SCORE: " + std::to_string(pGame->playerScore) + " \n PRESS ENTER TO START OVER!");

	pWindow->draw(gameOverText);

	pWindow->display();
}