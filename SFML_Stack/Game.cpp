#include "Game.h"

Game::Game(const unsigned int window_width, const unsigned int window_height, const std::string & window_title)
	:
	windowWidth(window_width),
	windowHeight(window_height)
{
	//Creates the game window
	pWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), window_title);
}

void Game::Loop()
{
	sf::Event event;
	//runs as long as the window is open
	while (pWindow->isOpen())
	{
		//Checks which events happened
		while (pWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				pWindow->close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					//Creates a block and sets it to the top of the window
					mQueue.PushBlock();
				}
				break;
			}
		}
		
		pWindow->clear();
		if (!mQueue.IsEmpty())
		{
			mQueue.DrawAll(pWindow);
			mQueue.MoveAll();
			if (mQueue.HeadOffWindow())
				mQueue.CutHead();
		}
		pWindow->display();
	}
}
