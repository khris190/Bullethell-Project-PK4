#include "Object.h"

#pragma region constructors

Object::Object()
{
}

Object::Object(const char *filename)
{
	bitmapa = new MyBitmap(filename);
	sizeX = al_get_bitmap_width(bitmapa->image);
	sizeY = al_get_bitmap_height(bitmapa->image);
}

Object::Object(const char *filename, int posX, int posY, int x) : Hitbox::Hitbox(posX, posY, x)
{
	bitmapa = new MyBitmap(filename);
	sizeX = al_get_bitmap_width(bitmapa->image);
	sizeY = al_get_bitmap_height(bitmapa->image);
}

Object::Object(const char *filename, int posX, int posY, int x, int y) : Hitbox::Hitbox(posX, posY, sizeX / 2 - 1 , sizeY / 2 - 1)
{
	bitmapa = new MyBitmap(filename);
	sizeX = al_get_bitmap_width(bitmapa->image);
	sizeY = al_get_bitmap_height(bitmapa->image);
}



#pragma endregion


void Object::DrawObject(int x, int y, double rotation, float scale)
{
	al_draw_scaled_rotated_bitmap(GetBitmap(), sizeX / 2, sizeY / 2, x, y, scale, scale, rotation, 0);
}
void Object::DrawObjecttest(int x, int y, double rotation, int scale)
{
	al_draw_bitmap(GetBitmap(), x, y, 0);
}
void Object::ChangeBitmap(const char *filename) 
{
	bitmapa->ChangeBitmap(filename);
}

//bool Object::CollisionCalculate(double x, double y, double objX, double objY, int objBouncerX, int objBouncerY)
//{
//	if (x  < objX + objBouncerX + boundryX
//		&& x > objX - objBouncerX - boundryX
//		&& y  < objY + objBouncerY + boundryY
//		&& y  > objY - objBouncerY - boundryY)
//	{
//		return true;
//	}
//	return false;
//}



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
	delete bitmapa;
}
