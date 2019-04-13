#pragma once
#include "Block.h"
class Queue
{
public:
	Queue() = default;
	~Queue() = default;

	void PushBlock();
	const bool IsEmpty() const;
	void DrawAll(sf::RenderWindow *pWindow) const;
	void MoveAll(const float elapsedTime);
	void CutHead();
	const bool TailInWindow() const;
	const bool HeadOffWindow() const;
	void Remove();
private:
	Block *head = nullptr;
	int colorShader = 40;
};

