#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Definitions.h"

int main()
{
	Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	game.Loop();

	return EXIT_SUCCESS;
}