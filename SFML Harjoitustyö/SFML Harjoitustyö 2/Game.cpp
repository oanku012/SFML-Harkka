#include "Game.hpp"

Game::Game() {

	//Set gamearea to empty and place player's head to the starting position
	for (int i = 0; i < GameConstants::levelWidth; i++) {
		for (int j = 0; j < GameConstants::levelHeight; j++) {
			if (i != startingPosX || j != startingPosY) {
				gameArea[i][j] = GameConstants::LevelSpace::Empty;
			}
			else {
				gameArea[i][j] = GameConstants::LevelSpace::Snake;
			}
		}
	}

	//Set the position of the worm's "tail" based on starting size and direction of the player
	switch (playerDirection)
	{
	case GameConstants::PlayerDirection::Right:
		for (int i = 1; i < playerSize; i++) {
			if ((startingPosX - i) >= 0) {
				
				snakeTailPosX = startingPosX - i;
				snakeTailPosY = startingPosY;
				gameArea[startingPosY][snakeTailPosX] = GameConstants::LevelSpace::Snake;

			}
			else {//Not sure if the error will be a problem, but the idea is to place snake parts correctly to the other side of the level if starting at the edge
				
				snakeTailPosX = (GameConstants::levelWidth + 1) + (startingPosX - i);
				snakeTailPosY = startingPosY;
				gameArea[startingPosY][snakeTailPosX] = GameConstants::LevelSpace::Snake;
			}
		}
		break;
	case GameConstants::PlayerDirection::Left:
		for (int i = 1; i < playerSize; i++) {
			if ((startingPosX + i) <= GameConstants::levelWidth)
			{
				snakeTailPosX = startingPosX + i;
				snakeTailPosY = startingPosY;

				gameArea[startingPosY][snakeTailPosX] = GameConstants::LevelSpace::Snake;
			}
			else {
				
				snakeTailPosX = -1 + (startingPosX + i) - GameConstants::levelWidth;
				snakeTailPosY = startingPosY;
				gameArea[startingPosY][snakeTailPosX] = GameConstants::LevelSpace::Snake;
			}
		}
		break;
	case GameConstants::PlayerDirection::Forward:
		for (int i = 1; i < playerSize; i++) {
			if ((startingPosY - i) >= 0) {
				snakeTailPosX = startingPosX;
				snakeTailPosY = startingPosY - i;

				gameArea[snakeTailPosY][startingPosX] = GameConstants::LevelSpace::Snake;
			}
			else {
				snakeTailPosX = startingPosX;
				snakeTailPosY = (GameConstants::levelHeight + 1) + (startingPosY - i);

				gameArea[snakeTailPosY][startingPosX] = GameConstants::LevelSpace::Snake;
			}
		}
		break;
	case GameConstants::PlayerDirection::Backward:
		for (int i = 1; i < playerSize; i++) {
			if ((startingPosY + i) <= GameConstants::levelHeight) {
				snakeTailPosX = startingPosX;
				snakeTailPosY = startingPosY + i;

				gameArea[snakeTailPosY][startingPosX] = GameConstants::LevelSpace::Snake;
			}
			else {
				snakeTailPosX = startingPosX;
				snakeTailPosY = -1 + (startingPosY + i) - GameConstants::levelHeight;

				gameArea[snakeTailPosY][startingPosX] = GameConstants::LevelSpace::Snake;
			}
		}
		break;
	default:
		break;
	}

	snakeHeadPosX = startingPosX;
	snakeHeadPosY = startingPosY;

}

void Game::Update(sf::Time delta) {

	//Move player in a direction
	switch (playerDirection)
	{
	case GameConstants::PlayerDirection::Right:
		int newPosX = snakeHeadPosX+1;

		if (newPosX <= GameConstants::levelWidth) {
			snakeHeadPosX = newPosX;
		}
		else {
			snakeHeadPosX = 0;
		}

		

		break;
	case GameConstants::PlayerDirection::Left:
		int newPosX = snakeHeadPosX - 1;

		if (newPosX >= 0) {
			snakeHeadPosX = newPosX;
		}
		else {
			snakeHeadPosX = GameConstants::levelWidth;
		}

		break;
	case GameConstants::PlayerDirection::Forward:
		int newPosY = snakeHeadPosY + 1;

		if (newPosY <= GameConstants::levelHeight) {
			snakeHeadPosY = newPosY;
		}
		else {
			snakeHeadPosY = 0;
		}
		break;
	case GameConstants::PlayerDirection::Backward:
		int newPosY = snakeHeadPosY - 1;

		if (newPosX >= 0) {
			snakeHeadPosY = newPosX;
		}
		else {
			snakeHeadPosY = GameConstants::levelHeight;
		}

		break;
	default:
		break;
	}

	gameArea[snakeHeadPosY][snakeHeadPosX] = GameConstants::LevelSpace::Snake;
	gameArea[snakeTailPosY][snakeTailPosX] = GameConstants::LevelSpace::Empty;

}

//Places a new piece of food on the level
void Game::PlaceFood() {
	
	int positionX;
	int positionY;

	srand(time(0));
	
	//Find a random position to place food in, if position is not empty, find another position
	do {
		positionX = (rand() % GameConstants::levelWidth);
		positionY = (rand() % GameConstants::levelHeight);

	} while (gameArea[positionY][positionY] != GameConstants::LevelSpace::Empty);

	gameArea[positionY][positionX] = GameConstants::LevelSpace::Food;
	
}

//Extend the snake's length after food has been eaten
void Game::ExtendSnake() {
	playerSize++;

	
}