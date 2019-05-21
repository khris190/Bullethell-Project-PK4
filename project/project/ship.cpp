#include "ship.h"

ship::ship() : Object::Object()
{
	playerWeapons = new Weapons(player);
	speed = 5;
}
ship::ship(const char *filename, int x, int y, int radius) : Object::Object(filename, x, y, radius)
{
	playerWeapons = new Weapons(player);
	speed = 5;
}
ship::ship(const char *filename, int x, int y, int radius, int s) : Object::Object(filename,x, y, radius)
{
	playerWeapons = new Weapons(player);
	speed = s;
}

double ship::GetX()
{
	return *posX;
}
double ship::GetY()
{
	return *posY;
}
double ship::GetSpeed()
{
	return speed;
}

void ship::calculatePosition()
{
	
}

void ship::DrawShip(int x, int y, int rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}

ship::~ship()
{
	delete playerWeapons;
}
