#include "Queue.h"

Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::PushBlock()
{
	if (IsEmpty())
		head = new Block(colorShader);
	else
	{
		head->AddToEnd(colorShader);
	}
	colorShader += 40;
	if (colorShader > 255)
		colorShader = 40;
}

const bool Queue::IsEmpty() const
{
	return head == nullptr;
}

void Queue::DrawAll(sf::RenderWindow *pWindow) const
{
	Block *tmp = head;
	while (tmp != nullptr)
	{
		tmp->Draw(pWindow);
		tmp = tmp->GetNext();
	}
}

void Queue::MoveAll()
{
	Block *tmp = head;
	while (tmp != nullptr)
	{
		tmp->Move();
		tmp = tmp->GetNext();
	}
}

void Queue::CutHead()
{
	Block *tmp = head;
	head = tmp->GetNext();
	delete tmp;
}

const bool Queue::HeadOffWindow() const
{
	return head->GetPosition() > WINDOW_HEIGHT;
}
