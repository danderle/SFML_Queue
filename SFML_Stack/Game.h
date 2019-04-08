#pragma once
#include <SFML/Graphics.hpp>

//Game class handles the game loop and game related objects
class Game
{
public:
	Game() = delete;
	//Overloaded constructor takes in parameters for the window
	Game(const unsigned int window_height, const unsigned int window_width, const std::string &window_title);
	~Game() = default;

	void Loop();

private:
	sf::RenderWindow *pWindow;
};

