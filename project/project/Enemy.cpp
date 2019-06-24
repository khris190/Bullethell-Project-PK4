#include "Enemy.h"



Enemy::Enemy() : ship::ship()
{
}

Enemy::Enemy(const char *filename, int x, int y, double speed, int period) : ship::ship(filename, x, y, 16, speed, 30)
{
	playerWeapons = new Weapons(enemy);
	this->period = period;
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

void Enemy::calculatePosition(double offsetX, double offsetY, double xCubed, double xScuared, double x)
{
	
}

void Enemy::DrawEntity(int x, int y, double rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}

Enemy::~Enemy()
{
	delete playerWeapons;
}
