#pragma once

#ifndef Game_hpp
#define Game_hpp
#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>
#include "GameConstants.hpp"

class Game {

public:
	Game();
	void Update(sf::Time delta);
	void PlaceFood();
	void ExtendSnake();

	GameConstants::LevelSpace gameArea[GameConstants::levelWidth][GameConstants::levelHeight];

	int playerSize;

	int startingPosX, startingPosY;

	GameConstants::PlayerDirection playerDirection;

	int snakeHeadPosX, snakeHeadPosY;
	int snakeTailPosX, snakeTailPosY;
	
	//Add a dictionary here to keep track of snake positions?
	std::map<int, int, int> snakeParts;
};


#endif /* Game_hpp */