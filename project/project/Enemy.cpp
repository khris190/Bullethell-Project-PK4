#include "Enemy.h"



Enemy::Enemy() : ship::ship()
{
}

Enemy::Enemy(const char *filename, int x, int y, double speed) : ship::ship(filename, WindowWidth / 2, WindowHeight - 32, x, 30)
{
	playerWeapons = new Weapons(enemy);
	this->speed = speed;
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

void Enemy::DrawEntity(int x, int y, int rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}



Enemy::~Enemy()
{
	delete playerWeapons;
}
