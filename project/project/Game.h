#pragma once
#include "allegro5\allegro5.h"
#include "allegro5/allegro_native_dialog.h"
#include "ALgif5/src/algif.h"
#include <iostream>
#include "Config.h"
#include "Object.h"
#include "MyBitmap.h"
#include "Player.h"
#include "Bullets.h""
#include "data.h"
#include <math.h>
class Game
{
private:
	 int result = 0;
public:

	 Game();
	 static void *Func_ThreadBulletsCalculations(ALLEGRO_THREAD *thr, void *arg);
	static int mainloop();
	~Game();
};

