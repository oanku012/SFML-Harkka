#pragma once

#ifndef Game_hpp
#define Game_hpp
#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <list>
#include "GameConstants.hpp"

class Game {

public:
	Game();
	void Update();
	void PlaceFood();
	//void GameOver();
	void StartNewGame();
	//void ExtendSnake();

	GameConstants::LevelSpace gameArea[GameConstants::levelWidth][GameConstants::levelHeight];

	int playerScore;

	int playerStartingSize;

	int startingPosX, startingPosY;

	GameConstants::PlayerDirection playerDirection;

	int snakeHeadPosX, snakeHeadPosY;
	int snakeTailPosX, snakeTailPosY;
	
	//Keeps track of snake parts so the tail can be removed on each frame
	std::map<int, std::pair<int, int>> snakeParts;

	//std::list<std::pair<int, int>> snakeParts;
	//std::pair<int, int> snakeParts;

	bool foodEaten, gameOver;
};


#endif /* Game_hpp */