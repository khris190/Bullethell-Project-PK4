#include "allegro5\allegro5.h"
#include <iostream>
#include "Config.h"
#include "Object.h"
#include "Game.h"
#define ALLEGRO_USE_CONSOLE



int main()
{	
	return Game::mainloop();
}