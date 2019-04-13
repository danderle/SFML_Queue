#include "Block.h"

Block::~Block()
{
	delete pRect;
	pRect = nullptr;
}

Block::Block(const unsigned int colorShader)
{
	//Creates the rectangle
	pRect = new sf::RectangleShape(sf::Vector2f(blockWidth, blockheight));
	pRect->setPosition(WINDOW_WIDTH / 2 - blockWidth / 2, -blockheight / 2);
	pRect->setFillColor(sf::Color(0, colorShader, 0));
}

void Block::Move()
{
	//Moves the block towards the bottom of the page
	if (pRect->getPosition().y < WINDOW_HEIGHT)
	{
		float elapsedTime = mClock.getElapsedTime().asSeconds();
		pRect->move(0, 160 * elapsedTime);
		mClock.restart();
	}
}

void Block::Draw(sf::RenderWindow * pWindow) const
{
	pWindow->draw(*pRect);
}

Block * Block::GetNext() const
{
	return pNext;
}

void Block::AddToEnd(const unsigned int colorShader)
{
	if (pNext == nullptr)
		pNext = new Block(colorShader);
	else
		pNext->AddToEnd(colorShader);
}

const bool Block::IsEmpty() const
{
	return pRect == nullptr;
}

const float Block::GetPosition() const
{
	return pRect->getPosition().y;
}
