#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define _DEBUG
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif
#include "allegro5\allegro5.h"
#include <iostream>
#include "Config.h"
#include "Object.h"
#include "Game.h"


#define ALLEGRO_USE_CONSOLE



int main()
{	
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int test = Game::mainloop();
	_CrtDumpMemoryLeaks();

	return test;
}