#pragma once

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <stdio.h>
#include "Game.hpp"
#include <SFML/Graphics.hpp>

class InputHandler {

public:
    InputHandler(sf::RenderWindow* w, Game* pg);
    void processEvents();

private:

    sf::RenderWindow* pWindow;
    //Player* pPlayer;
    Game* pGame;

    // Try to do a boolean system for controls
    bool bPlayerMoveUp = false;
    bool bPlayerMoveDown = false;
    bool bPlayerMoveLeft = false;
    bool bPlayerMoveRight = false;

    // What about player two???
    //bool bPlayerTwoMoveUp = false;
};

#endif /* InputHandler_hpp */