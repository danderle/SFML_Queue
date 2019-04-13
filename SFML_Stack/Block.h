#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Block
{
public:
	Block() = delete;
	Block(const unsigned int colorShader);
	~Block();

	void Move(const float elapsedTime);
	void Draw(sf::RenderWindow *pWindow) const;
	Block* GetNext() const;
	void AddToEnd(const unsigned int colorShader);
	const bool IsEmpty() const;
	const float GetPosition() const;
	sf::RectangleShape* GetRect() const;
	const bool OnWayOut() const;
	void ToBeDeleted();

private:
	static constexpr float blockWidth = 80;
	static constexpr float blockheight = 80;

	bool mOnWayOut = false;

	sf::RectangleShape *pRect = nullptr;
	Block *pNext = nullptr;

};

