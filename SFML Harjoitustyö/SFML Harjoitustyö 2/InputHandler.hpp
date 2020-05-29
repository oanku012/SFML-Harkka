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

};

#endif /* InputHandler_hpp */