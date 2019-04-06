#include "Object.h"


Object::Object()
{
}
Object::Object(const char *filename)
{
	bitmapa = new MyBitmap(filename);
	sizeX = al_get_bitmap_width(bitmapa->image);
	sizeY = al_get_bitmap_height(bitmapa->image);
	bouncerX = sizeX / 2 - 1;
	bouncerY = sizeY / 2 - 1;
}

Object::Object(const char *filename, int x, int y)
{
	bitmapa = new MyBitmap(filename);
	sizeX = al_get_bitmap_width(bitmapa->image);
	sizeY = al_get_bitmap_height(bitmapa->image);
	bouncerX = x / 2 - 1;
	bouncerY = y / 2 - 1;
}


void Object::DrawObject(int x, int y, double rotation, int scale)
{
	al_draw_scaled_rotated_bitmap(GetBitmap(), sizeX / 2, sizeY / 2, x, y, scale, scale, rotation, 0);
}


void Object::ChangeBitmap(const char *filename) 
{
	bitmapa->ChangeBitmap(filename);
}

bool Object::CollisionCalculate(double x, double y, double objX, double objY, int objBouncerX, int objBouncerY)
{
	if (x  < objX + objBouncerX + bouncerX
		&& x > objX - objBouncerX - bouncerX
		&& y  < objY + objBouncerY + bouncerY
		&& y  > objY - objBouncerY - bouncerY)
	{
		return true;
	}
	return false;
}



ALLEGRO_BITMAP *Object::GetBitmap() 
{
	if (bitmapa != NULL)
	{
		return bitmapa->image;
	}
	return NULL;
	
}

Object::~Object()
{

}
