#include "Block.h"

Block::~Block()
{
	delete pRect;
	pRect = nullptr;
}

Block::Block(const unsigned int colorShader)
{
	//Creates the rectangle and sets all settings
	pRect = new sf::RectangleShape(sf::Vector2f(blockWidth, blockheight));
	pRect->setPosition(WINDOW_WIDTH / 2 - blockWidth / 2, -blockheight);
	pRect->setFillColor(sf::Color(0, colorShader, 0));
	pRect->setOutlineColor(sf::Color::Blue);
	pRect->setOutlineThickness(-5.0f);
}

void Block::Move(const float elapsedTime)
{
	//Moves the block towards the bottom of the page
	if (pRect->getPosition().y < WINDOW_HEIGHT)
	{
		pRect->move(0, 200 * elapsedTime);
	}
}

void Block::Draw(sf::RenderWindow * pWindow) const
{
	pWindow->draw(*pRect);
}

Block* Block::GetNext() const
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

sf::RectangleShape * Block::GetRect() const
{
	return pRect;
}

const bool Block::OnWayOut() const
{
	return mOnWayOut;
}

void Block::ToBeDeleted()
{
	mOnWayOut = true;
	pRect->setFillColor(sf::Color::Red);
}
