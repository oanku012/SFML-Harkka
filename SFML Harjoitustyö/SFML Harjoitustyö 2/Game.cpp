#include "Game.hpp"

Game::Game() {

	StartNewGame();

}

void Game::StartNewGame() {

	gameOver = false;

	playerDirection = GameConstants::PlayerDirection::Right;
	playerScore = 0;
	playerStartingSize = 3;

	startingPosX = 8;
	startingPosY = 8;


	snakeParts.clear();

	//Set the head position into the map/dictionary
	snakeParts[0].first = startingPosY;
	snakeParts[0].second = startingPosX;

	//std::cout << playerDirection;

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

	//Set the position of the worm's "tail" based on starting size and direction of the player, set each snake part into the map with an index lower than the head
	switch (playerDirection)
	{
	case GameConstants::PlayerDirection::Right:
		for (int i = 1; i < playerStartingSize; i++) {
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

			snakeParts[-i].first = snakeTailPosX;
			snakeParts[-i].second = snakeTailPosY;

		}
		break;
	case GameConstants::PlayerDirection::Left:
		for (int i = 1; i < playerStartingSize; i++) {
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

			snakeParts[-i].first = snakeTailPosX;
			snakeParts[-i].second = snakeTailPosY;
		}
		break;
	case GameConstants::PlayerDirection::Forward:
		for (int i = 1; i < playerStartingSize; i++) {
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

			snakeParts[-i].first = snakeTailPosX;
			snakeParts[-i].second = snakeTailPosY;
		}
		break;
	case GameConstants::PlayerDirection::Backward:
		for (int i = 1; i < playerStartingSize; i++) {
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
			snakeParts[-i].first = snakeTailPosX;
			snakeParts[-i].second = snakeTailPosY;
		}
		break;
	default:
		break;
	}

	snakeHeadPosX = startingPosX;
	snakeHeadPosY = startingPosY;

	PlaceFood();
}

void Game::Update() {
	
		int newPosX = 0;
		int newPosY = 0;

		foodEaten = false;

		//Move player in a direction
		switch (playerDirection)
		{
		case GameConstants::PlayerDirection::Right:
			newPosX = snakeHeadPosX + 1;

			if (newPosX <= GameConstants::levelWidth - 1) {
				snakeHeadPosX = newPosX;
			}
			else {
				snakeHeadPosX = 0;
			}

			break;
		case GameConstants::PlayerDirection::Left:
			newPosX = snakeHeadPosX - 1;

			if (newPosX >= 0) {
				snakeHeadPosX = newPosX;
			}
			else {
				snakeHeadPosX = GameConstants::levelWidth - 1;
			}

			break;
		case GameConstants::PlayerDirection::Forward:
			newPosY = snakeHeadPosY - 1;

			if (newPosY >= 0) {
				snakeHeadPosY = newPosY;
			}
			else {
				snakeHeadPosY = GameConstants::levelHeight - 1;
			}
			break;
		case GameConstants::PlayerDirection::Backward:
			newPosY = snakeHeadPosY + 1;

			if (newPosY <= GameConstants::levelHeight - 1) {
				snakeHeadPosY = newPosY;
			}
			else {
				snakeHeadPosY = 0;
			}

			break;
		default:
			break;
		}

		if (gameArea[snakeHeadPosY][snakeHeadPosX] == GameConstants::LevelSpace::Empty) {
			//If new position to move to is empty, replace new position with snake and set old tail position as empty
			gameArea[snakeHeadPosY][snakeHeadPosX] = GameConstants::LevelSpace::Snake;
			gameArea[snakeTailPosY][snakeTailPosX] = GameConstants::LevelSpace::Empty;

		}
		else if (gameArea[snakeHeadPosY][snakeHeadPosX] == GameConstants::LevelSpace::Snake) {
			//if new position to move has snake, game over
			gameOver = true;
		}
		else if (gameArea[snakeHeadPosY][snakeHeadPosX] == GameConstants::LevelSpace::Food) {
			//If new position to move to has food, replace new position with snake and extend snake
			gameArea[snakeHeadPosY][snakeHeadPosX] = GameConstants::LevelSpace::Snake;
			playerScore++;
			foodEaten = true;


		}

		if (gameOver == false) {

			//std::cout << snakeParts.begin()->first << "\n";

			//std::cout << snakeParts.size();

			std::cout << "X:" << snakeTailPosX << " Y:" << snakeTailPosY << " \n";

			//std::cout << "X:" << snakeParts.begin()->second.first << " Y:" << snakeParts.begin()->second.second << " \n" ;

			//std::cout << snakeParts[-2 +1].first;


			//This for loop just wouldn't run at all for some reason
			//Changes the position values in the snakepart map to correspond with the movement
			/*for (int i = snakeParts.begin()->first; i < (i + snakeParts.size()); i++) {

				std::cout << "Bruhh";

				if (i < 0) {
					snakeParts[i].first = snakeParts[i + 1].first;

					snakeParts[i].second = snakeParts[i + 1].second;

					std::cout << snakeParts[i].first << " " << snakeParts[i].second << " \n";
				}
				else {
					//This should apply the new head position at the end of the map
					snakeParts[i].first = snakeHeadPosY;
					snakeParts[i].second = snakeHeadPosX;

					std::cout << snakeParts[i].first << " " << snakeParts[i].second << " \n";
				}
			}*/

			//Changes the position values in the snakepart map to correspond with the movement
			for (std::map<int, std::pair<int, int>>::iterator it = snakeParts.begin(); it != snakeParts.end(); ++it) {
				if (it->first < snakeParts.rbegin()->first) {

					it->second = snakeParts[it->first + 1];
				}
				else {
					it->second.first = snakeHeadPosX;
					it->second.second = snakeHeadPosY;
				}
			}




			//If the snake ate food, extend snake length and place a new piece of food on the level
			if (foodEaten) {
				snakeParts[(snakeParts.begin()->first) - 1].first = snakeTailPosX;
				snakeParts.begin()->second.second = snakeTailPosY;

				PlaceFood();
			}

			//Gets the first element of the snakemap and assigns it as the new tail 
			snakeTailPosX = snakeParts.begin()->second.first;
			snakeTailPosY = snakeParts.begin()->second.second;
		}
	
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

	} while (gameArea[positionY][positionX] != GameConstants::LevelSpace::Empty);

	gameArea[positionY][positionX] = GameConstants::LevelSpace::Food;
	
}



