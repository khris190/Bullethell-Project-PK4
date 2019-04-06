#pragma once
#include "allegro5\allegro5.h"
#include "MyBitmap.h"
#include "Config.h"
class Object
{
private:
	MyBitmap * bitmapa = NULL;

public:

	int bouncerX;
	int bouncerY;
	Object(const char *filename);
	Object(const char *filename, int x, int y);

	void ChangeBitmap(const char *filename);
	bool CollisionCalculate(double x, double y, double objX, double objY, int objBouncerX, int objBouncerY);
	ALLEGRO_BITMAP *GetBitmap();
	Object();
	~Object();
protected: void DrawObject(int x, int y, double rotation = 0, int scale = 1);
		   int sizeX;
		   int sizeY;
		   

};

