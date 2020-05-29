#pragma once

#ifndef GameConstants_hpp
#define GameConstants_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#define BGCOLOR 132,174,104
#define WORMCOLOR 95,52,58
#define FOODCOLOR 30,30,30

// Below color definition is not used for now...
#define FGCOLOR 0,0,0


class GameConstants {

public:
    static const int iScreenWidth = 800;
    static const int iScreenHeight = 800;

    static const int levelWidth = 32;
    static const int levelHeight = 32;

    static const enum LevelSpace
    {
    Empty, Snake, Food
    }; 
    
    static const enum PlayerDirection {
    Right, Left, Forward, Backward
    };

    //const static sf::Color bgColor;

};

#endif /* GameConstants_hpp */
