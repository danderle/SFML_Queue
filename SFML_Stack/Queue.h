#pragma once
#include "Block.h"
class Queue
{
public:
	Queue() = default;
	~Queue() = default;

	void PushBlock(const float viewHeight);
	const bool IsEmpty() const;
	const int Size() const;
	void DrawAll(sf::RenderWindow *pWindow) const;
	void MoveAll(const float elapsedTime);
	void CutHead();
	const bool TailInView(const float viewHeight) const;
	const bool HeadOffWindow() const;
	void Remove();
	const int GetHeight() const;
private:
	Block *head = nullptr;
	int mBlockColor = 40;
};

