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
    void render(sf::Time delta);
    
private:
    // We need a member variable where we render everything
    sf::RenderWindow* pWindow;
    //Game* pGame;
    
    int counter;    
    sf::CircleShape circle;
    std::vector<sf::CircleShape> vec_circles;
    
    sf::RectangleShape rect;
    
    // For drawing some text
    sf::Font font;
    sf::Text text;
    sf::Text debug;
    
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Texture tx_player;
    sf::Sprite sp_player;
    
    
    sf::Texture mytexture;
    
  

};

#endif /* renderer_hpp */
