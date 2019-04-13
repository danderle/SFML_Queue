#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Block
{
public:
	Block() = delete;
	Block(const unsigned int colorShader);
	~Block();

	void Move();
	void Draw(sf::RenderWindow *pWindow) const;
	Block* GetNext() const;
	void AddToEnd(const unsigned int colorShader);
	const bool IsEmpty() const;
	const float GetPosition() const;

private:
	static constexpr float blockWidth = 80;
	static constexpr float blockheight = 80;

	int colorShader = 40;
	sf::RectangleShape *pRect = nullptr;
	sf::Clock mClock;
	Block *pNext = nullptr;
};

