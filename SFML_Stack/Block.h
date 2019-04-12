#pragma once
#include <SFML/Graphics.hpp>
class Block
{
public:
	Block() = default;
	~Block();

	void CreateBlock(const unsigned int windowWidth, const unsigned int windowHeight);
	void Move();
	void Draw(sf::RenderWindow *pWindow) const;
	const bool IsEmpty() const;
private:
	static constexpr float blockWidth = 80;
	static constexpr float blockheight = 80;

	unsigned int windowHeight;
	unsigned int windowWidth;

	int colorShader = 40;
	sf::Clock mClock;
	sf::RectangleShape *pRect = nullptr;
};

