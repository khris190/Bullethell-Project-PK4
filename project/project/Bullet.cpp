#include "Bullet.h"

Bullet::Bullet(double rotation, double posX, double posY, double speedX, double speedY) : Hitbox::Hitbox(posX, posY)
{

	this->rotation = rotation;
	this->speedX = speedX;
	this->speedY = speedY;
}
Bullet::Bullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX) : Hitbox::Hitbox(posX, posY, sizeX / 2 - 1)
{
	this->rotation = rotation;
	this->speedX = speedX;
	this->speedY = speedY;

}
Bullet::Bullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX, double sizeY) : Hitbox::Hitbox(posX, posY, sizeX / 2 - 1, sizeY / 2 - 1)
{
	this->rotation = rotation;
	this->speedX = speedX;
	this->speedY = speedY;
}


double Bullet::GetRotation()
{
	return  rotation;
}
int Bullet::calculate()
{
	*posX += speedX;
	*posY += speedY;
	if (*posX < 0 || *posX > WindowWidth)
	{
		return 0;
	}
	else if(*posY < 0 || *posY > WindowHeight)
	{
		return 0;
	}
	return 1;
}


Bullet::~Bullet()
{
}
