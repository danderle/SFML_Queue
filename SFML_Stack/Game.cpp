#include "Game.h"

Game::Game(const unsigned int window_height, const unsigned int window_width, const std::string & window_title)
{
	pWindow = new sf::RenderWindow(sf::VideoMode(window_height, window_width), window_title);
}

void Game::Loop()
{
	sf::Event event;
	while (pWindow->isOpen())
	{

		while (pWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				pWindow->close();
				break;
			}
		}
		pWindow->clear();
		pWindow->display();
	}
}
