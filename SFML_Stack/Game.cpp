#include "Game.h"
#include <iostream>

Game::Game(const unsigned int window_width, const unsigned int window_height, const std::string & window_title)
	:
	windowWidth(window_width),
	windowHeight(window_height)
{
	//Creates the game window
	pWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), window_title);
	if (!mFont.loadFromFile(FONT_FILEPATH))
	{
		std::cout << "failed to load the fonts" << std::endl;
	}
	//Settings for the text up top
	mText.setFont(mFont);
	mText.setCharacterSize(20);
	mText.setFillColor(sf::Color::Red);
	mText.setOutlineColor(sf::Color::Yellow);
	mText.setOutlineThickness(6);
	mText.setString("Press \"Enter\" to make a Queue");
	
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
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					//Checks if last created block is inside window so no new block overlaps
					if (mQueue.TailInWindow())
					{
						//Creates a block and sets it to the top of the window
						mQueue.PushBlock();
						mClock.restart();
					}
				}
				else if (event.key.code == sf::Keyboard::Key::Delete)
				{
					if (!mQueue.IsEmpty())
					{
						//If Head exists it will be moved off screen to be deleted
						mQueue.Remove();
					}
				}
				break;
			}
		}
		
		//Clears the window
		pWindow->clear();

		//Gets the passed time to adjust to different frame rates
		float elapsedTime = mClock.getElapsedTime().asSeconds();
		mClock.restart();
		//If queue is empty skip drawing it
		if (!mQueue.IsEmpty())
		{
			//Draws the blocks and then moves them
			mQueue.DrawAll(pWindow);
			mQueue.MoveAll(elapsedTime);
			//if the head of the queue moves off window, delete it
			if (mQueue.HeadOffWindow())
				mQueue.CutHead();
		}
		pWindow->draw(mText);
		pWindow->display();
		
	}
}
