#include "MyBitmap.h"



MyBitmap::MyBitmap(const char *filename)
{
	image = al_load_bitmap(filename);
}


void MyBitmap::ChangeBitmap(const char *filename)
{
	al_destroy_bitmap(image);
	image = al_load_bitmap(filename);
}
MyBitmap::~MyBitmap()
{
	al_destroy_bitmap(image);
}
