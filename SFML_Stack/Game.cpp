#include "Game.h"
#include <iostream>

Game::Game(const unsigned int window_width, const unsigned int window_height, const std::string & window_title)
{
	//TESTING CODE YELLOW FRAME
	frame.setSize(sf::Vector2f(window_width, window_height));
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineColor(sf::Color::Yellow);
	frame.setOutlineThickness(-10.0f);

	//Creates the game window
	pWindow = new sf::RenderWindow(sf::VideoMode(window_width, window_height), window_title);
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
				//TESTING CODE PRESS T
				if (event.key.code == sf::Keyboard::Key::T)
				{
					mView.zoom(1.5f);
					float centerY = WINDOW_HEIGHT - mView.getSize().y/2.0f;
					mView.setCenter(WINDOW_WIDTH / 2, centerY);
					pWindow->setView(mView);
					mText.setPosition(WINDOW_WIDTH/2 - mView.getSize().x, WINDOW_HEIGHT - mView.getSize().y);
				}
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					float currentViewHeight = mView.getSize().y;
					//Checks if last created block is inside window so no new block overlaps
					if (mQueue.TailInView(currentViewHeight))
					{
						//Creates a block and sets it to the top of the window
						mQueue.PushBlock(currentViewHeight);
						mClock.restart();
						mView = pWindow->getView();
						if (mQueue.GetHeight() > (currentViewHeight * 2.0f / 3.0f))
						{
							//Zooms the view and sets the bottom of new and original frame on top of each other
							mView.zoom(1.5f);
							float centerY = WINDOW_HEIGHT - mView.getSize().y / 2.0f;
							mView.setCenter(WINDOW_WIDTH / 2, centerY);
							pWindow->setView(mView);
						}
					}
				}
				//Delete Blocks
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
		pWindow->draw(frame);
		pWindow->display();
		
	}
}
