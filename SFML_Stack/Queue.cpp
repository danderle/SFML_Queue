#include "Queue.h"

void Queue::PushBlock(const float viewHeight)
{
	if (IsEmpty())
		head = new Block(mBlockColor, viewHeight);
	else
	{
		head->AddToEnd(mBlockColor, viewHeight);
	}
	mBlockColor += 40;
	if (mBlockColor > 255)
		mBlockColor = 40;
}

const bool Queue::IsEmpty() const
{
	return head == nullptr;
}

const int Queue::Size() const
{
	if (head == nullptr)
		return 0;
	return head->Count();
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

void Queue::MoveAll(const float elapsedTime)
{
	//Moves the head to 2/3 of window height or to be deleted
	if (head->OnWayOut() || head->GetPosition() < WINDOW_HEIGHT * 2.0f / 3.0f)
	{
		head->Move(elapsedTime);
	}

	Block *prev = head;
	Block *next = head->GetNext();
	//cycles through all blocks
	while (next != nullptr)
	{
		//moves other blocks as long as they dont touch block infront or if they are to be deleted
		if(next->OnWayOut() ||
			(!next->GetRect()->getGlobalBounds().intersects(prev->GetRect()->getGlobalBounds()) &&
			next->GetPosition() < WINDOW_HEIGHT * 2.0f / 3.0f))
		{
			next->Move(elapsedTime);
		}
		prev = next;
		next = next->GetNext();
	}
}

void Queue::CutHead()
{
	Block *tmp = head;
	head = tmp->GetNext();
	delete tmp;
}

//Checks if the last block is completely in the window
const bool Queue::TailInView(const float viewHeight) const
{
	if (IsEmpty())
		return true;
	Block *tmp = head;
	while (tmp->GetNext() != nullptr)
	{
		tmp = tmp->GetNext();
	}
	return tmp->GetPosition() > (WINDOW_HEIGHT - viewHeight);
}

//checks if head is off window
const bool Queue::HeadOffWindow() const
{
	return head->GetPosition() > WINDOW_HEIGHT;
}

void Queue::Remove()
{
	Block *tmp = head;
	//cycle through all block until block is found which is not marked to be removed
	while (tmp->OnWayOut())
	{
		//break if tail is reached
		if (tmp->GetNext() == nullptr)
			break;
		tmp = tmp->GetNext();
	}
	tmp->ToBeDeleted();
}

const int Queue::GetHeight() const
{
	return head->GetRect()->getGlobalBounds().height * head->Count();
}
