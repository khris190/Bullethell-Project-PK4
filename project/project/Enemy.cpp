#include "Enemy.h"



Enemy::Enemy() : Object::Object()
{
}

Enemy::Enemy(const char *filename, int x, int y, double speedX, double speedY) : Object::Object(filename, WindowWidth / 2, WindowHeight - 32, x)
{
	playerWeapons = new Weapons(enemy);
	this->speedX = speedX;			
	this->speedY = speedY;
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
	*posX += speedX;
	*posY += speedY;
}

void Enemy::DrawPlayer(int x, int y, int rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}



Enemy::~Enemy()
{
	delete playerWeapons;
}
