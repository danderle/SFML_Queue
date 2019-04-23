#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Block
{
public:
	Block() = delete;
	Block(const unsigned int colorShader, const float viewHeight);
	~Block();

	void Move(const float elapsedTime);
	void Draw(sf::RenderWindow *pWindow) const;
	Block* GetNext() const;
	void AddToEnd(const unsigned int colorShader, const float viewHeight);
	const bool IsEmpty() const;
	int Count() const;
	const float GetPosition() const;
	sf::RectangleShape* GetRect() const;
	const bool OnWayOut() const;
	void ToBeDeleted();

private:
	static constexpr float mBlockWidth = 80;
	static constexpr float mBlockheight = 80;
	static constexpr float mBlockSpeed = 250;
	bool mOnWayOut = false;
	sf::RectangleShape *pRect = nullptr;
	Block *pNext = nullptr;

};

