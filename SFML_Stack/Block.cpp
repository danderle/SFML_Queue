#include "Block.h"

Block::~Block()
{
	delete pRect;
	pRect = nullptr;
}

void Block::CreateBlock(const unsigned int windowWidth, const unsigned int windowHeight)
{
	//Sets the window size
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	//Creates the rectangle
	pRect = new sf::RectangleShape(sf::Vector2f(blockWidth, blockheight));
	pRect->setPosition(windowWidth / 2 - blockWidth / 2, -blockheight / 2);
	pRect->setFillColor(sf::Color(0, colorShader, 0));
	colorShader += 40;
	if (colorShader > 255)
		colorShader = 0;
	//Restarts clock so so every new rect starts at the top
	mClock.restart();
}

void Block::Move()
{
	//Moves the block towards the bottom of the page
	if (pRect->getPosition().y < windowHeight)
	{
		float elapsedTime = mClock.getElapsedTime().asSeconds();
		pRect->move(0, 160 * elapsedTime);
		mClock.restart();
	}
	//if the block is outside window it gets deleted
	else if (pRect->getPosition().y > windowHeight)
	{
		delete pRect;
		pRect = nullptr;
	}
}

void Block::Draw(sf::RenderWindow * pWindow) const
{
	pWindow->draw(*pRect);
}

const bool Block::IsEmpty() const
{
	return pRect == nullptr;
}
