#include "Block.h"

Block::~Block()
{
	delete pRect;
	pRect = nullptr;
}

Block::Block(const unsigned int blockColor, const float viewHeight)
{
	//Creates the rectangle and sets all settings
	pRect = new sf::RectangleShape(sf::Vector2f(mBlockWidth, mBlockheight));
	pRect->setPosition(WINDOW_WIDTH / 2 - mBlockWidth / 2, (WINDOW_HEIGHT - viewHeight) -mBlockheight);
	pRect->setFillColor(sf::Color(0, blockColor, 0));
	pRect->setOutlineColor(sf::Color::Blue);
	pRect->setOutlineThickness(-5.0f);
}

void Block::Move(const float elapsedTime)
{
	//Moves the block towards the bottom of the page
	pRect->move(0, mBlockSpeed * elapsedTime);
}

void Block::Draw(sf::RenderWindow * pWindow) const
{
	pWindow->draw(*pRect);
}

Block* Block::GetNext() const
{
	return pNext;
}

void Block::AddToEnd(const unsigned int blockColor, const float viewHeight)
{
	if (pNext == nullptr)
		pNext = new Block(blockColor, viewHeight);
	else
		pNext->AddToEnd(blockColor, viewHeight);
}

const bool Block::IsEmpty() const
{
	return pRect == nullptr;
}

int Block::Count() const
{
	return pNext == nullptr ? 1 : 1 + pNext->Count();
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
