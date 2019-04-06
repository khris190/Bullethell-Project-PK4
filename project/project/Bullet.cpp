#include "Bullet.h"



Bullet::Bullet(double rotation, double posX, double posY, double speedX, double speedY)
{
	this->rotation = rotation;
	this->posX = posX;
	this->posY = posY;
	this->speedX = speedX;
	this->speedY = speedY;
}

double Bullet::GetX()
{
	return posX;
}
double Bullet::GetY()
{
	return posY;
}
double Bullet::GetRotation()
{
	return  rotation;
}
int Bullet::calculate()
{
	posX += speedX;
	posY += speedY;
	if (posX < 0 || posX > WindowWidth)
	{
		return 0;
	}
	else if(posY < 0 || posY > WindowHeight)
	{
		return 0;
	}
	return 1;
}


Bullet::~Bullet()
{
}
