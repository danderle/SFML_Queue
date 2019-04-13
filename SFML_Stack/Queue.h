#pragma once
#include "Block.h"
class Queue
{
public:
	Queue();
	~Queue();

	void PushBlock();
	const bool IsEmpty() const;
	void DrawAll(sf::RenderWindow *pWindow) const;
	void MoveAll();
	void CutHead();
	const bool HeadOffWindow() const;
private:
	Block *head = nullptr;
	int colorShader = 40;
};

