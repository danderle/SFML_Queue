#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Queue.h"

//Game class handles the game loop and game related objects
class Game
{
public:
	//No default constructor
	Game() = delete;
	//Overloaded constructor takes in parameters for the window
	Game(const unsigned int window_height, const unsigned int window_width, const std::string &window_title);
	//Default destructor
	~Game() = default;

	//Game Loop
	void Loop();
	

private:
	sf::RenderWindow *pWindow = nullptr;
	sf::Font mFont;
	sf::Text mText;
	sf::Clock mClock;
	sf::View mView;
	sf::RectangleShape frame;
	Queue mQueue;
};

