#pragma once
#include "allegro5\allegro5.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_image.h>
#include <string>

class MyBitmap
{
public:
	ALLEGRO_BITMAP * image = NULL;
	MyBitmap(const char *filename);
	void ChangeBitmap(const char *filename);
	~MyBitmap();
};

