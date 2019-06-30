#include "Enemy.h"




Enemy::Enemy(const char *filename, int x, int y, double speed, int period) : ship::ship(filename, x, y, 24, speed, 30)
{
	//playerWeapons = new Weapons(enemy);
	this->startX = x;
	this->startY = y;
	this->period = period;
}

Enemy::Enemy(const char *filename, int x, int y, double speed, double(*f2)(double x), int period) : ship::ship(filename, x, y, 24, speed, 30)
{
	//playerWeapons = new Weapons(enemy);
	this->startX = x;
	this->startY = y;
	this->period = period;
	this->f = f2;
}

void Enemy::EntityShot(Bullets *bullets, int timer)
{
	if (timer % period == 0)
	{
		bullets->AddBullet(0, GetX() , GetY() + 30, 0, 6, 3);
	}
}

double Enemy::GetHealth()
{
	if (*posX < 0 || *posX > WindowWidth)
	{
		return 0;
	}
	else if (*posY < 0 || *posY > WindowHeight)
	{
		return 0;
	}
	return health;
}
double Enemy::GetHealthAndBoundarys()
{
	/*if (*posX < 0 || *posX > WindowWidth)
	{
		return 0;
	}
	else*/ if (*posY < 0 || *posY > WindowHeight)
	{
		return 0;
	}
	return health;
}

double Enemy::GetX()
{
	return *posX;
}
double Enemy::GetY()
{
	return *posY;
}

void Enemy::calculatePosition()
{
	if (this->f != NULL)
	{
		*posY += GetSpeed();
		*posX += GetSpeed() * f((*posY - startY) / 50) * 2;
	}


}

void Enemy::DrawEntity(int x, int y, double rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}

Enemy::~Enemy()
{
	//delete playerWeapons;
}
