#include "ship.h"

ship::ship() : Object::Object()
{
	playerWeapons = new Weapons(player);
	speed = 5;
}
ship::ship(const char *filename, int x, int y, int radius, int health) : Object::Object(filename, x, y, radius)
{
	playerWeapons = new Weapons(player);
	speed = 5;
	this->health = health;
}
ship::ship(const char *filename, int x, int y, int radius, int s, int health) : Object::Object(filename,x, y, radius)
{
	playerWeapons = new Weapons(player);
	speed = s;
	this->health = health;
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

bool ship::CalculateCollisions(Bullets *bullets)
{
	Hitbox hTemp(*(this->posX.get()), *(this->posY.get()), this->radius);
	int result = 0;
	for (unsigned int i = 0; i < bullets->bullets.size(); i++)
	{
		if (bullets->bullets[i]->CalculateCollision(&hTemp))
		{
			Bullet *swapper = bullets->bullets[i];
			bullets->bullets[i] = bullets->bullets[bullets->bullets.size() - 1];
			bullets->bullets[bullets->bullets.size() - 1] = swapper;
			bullets->bullets.erase(bullets->bullets.end() - 1);
			delete swapper;
			result++;
		}
	}
	this->health -= result * bullets->damage;	
	if (this->health < 1)
	{
		return 1;
	}
	return 0;
	
}

void ship::DrawShip(int x, int y, int rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}

ship::~ship()
{
	delete playerWeapons;
}
