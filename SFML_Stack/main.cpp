#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 960
#define WINDOW_TITLE "Stack with linked list"

int main()
{
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	game.Loop();

	return EXIT_SUCCESS;
}