#pragma once
#ifndef renderer_hpp
#define renderer_hpp

#include <stdio.h>

#include "SFML/Graphics.hpp"
#include "Game.hpp"


#include <vector>

class renderer {
    
public:
    // Constructor, takes a pointer to renderwindow as a parameter
    renderer(sf::RenderWindow* pw, Game* pg);
    
    // This method does all the magic!!!
    void renderGame();
    void renderGameOver();
    
private:
    // We need a member variable where we render everything
    sf::RenderWindow* pWindow;
    Game* pGame;
    
    sf::RectangleShape background;
    
    sf::Text gameOverText;
  
    sf::Font drive;

};

#endif /* renderer_hpp */
