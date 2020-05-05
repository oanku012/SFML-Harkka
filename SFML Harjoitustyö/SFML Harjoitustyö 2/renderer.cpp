#include "renderer.hpp"
//#include "ResourcePath.hpp"
#include <iostream>
#include <cmath>

renderer::renderer(sf::RenderWindow* pw, Game* pg) {
	// Set our render window target
	this->pWindow = pw;


}

void renderer::render(sf::Time delta) 
	{
		// Clear the data
		pWindow->clear();

	};