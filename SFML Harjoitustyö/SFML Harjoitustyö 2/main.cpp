
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
//#include "ResourcePath.hpp"

// Include the game-class!
#include "Game.hpp"
// Include the renderer-class!
#include "Renderer.hpp"
// Include the input handler!
#include "InputHandler.hpp"

#include "GameConstants.hpp"

#include <iostream>

/*
#include <chrono>
#include <random>
#include <iostream>


// Test some stuff...
float randf(float min, float max)
{
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}
*/

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(GameConstants::iScreenWidth,
        GameConstants::iScreenHeight), "SFML window");

   

    // Don't repeat the keys...
    window.setKeyRepeatEnabled(false);
    // Repeat the keys...
    //window.setKeyRepeatEnabled(true);

    // Limit the frame rate
    window.setFramerateLimit(10);

    // Create the game-object
    Game myGame;

    // Create the renderer
    renderer* pMyRenderer = new renderer(&window, &myGame);

    // Create the input handler
    InputHandler myInputHandler(&window, &myGame);

    // Joysticks?
    /*for (int i = 0; i < 8; i++)
        std::cout << std::boolalpha << "Joystick " << i << " : "
        << sf::Joystick::isConnected(i) << std::endl;*/

    // Get rid of the annoying repeating log message...
    sf::err().rdbuf(NULL);

    // Start the game loop
    while (window.isOpen()) {
        // Game loop actions here:
        // Handle inputs
        myInputHandler.processEvents();

        // Measure time
       
        //std::cout << "Delta time: " << deltatime.asMicroseconds() << std::endl;

        if (myGame.gameOver == false) {
            // Update game state
            myGame.Update();


            // Render the game screen
            pMyRenderer->renderGame();

        }
        else {
            pMyRenderer->renderGameOver();
        }

        // Sleep.... this saves the CPU from burning.
        //sf::Time sleeptime = sf::microseconds(16000-deltatime.asMicroseconds());
        //sf::sleep(sleeptime);
    }

    // Release the memory
    delete(pMyRenderer);

    return EXIT_SUCCESS;
}