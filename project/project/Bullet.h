#pragma once
#include "Config.h"
#include "Hitbox.h"
class Bullet: public Hitbox
{
private:
	double rotation;
	double speedX;
	double speedY;
	double startY;
	
public:


	Bullet(double rotation, double posX, double posY, double speedX, double speedY);
	Bullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX);
	Bullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX, double sizeY);
	//Bullet operator=(const Bullet& bullet);
	double GetRotation();
	int calculate();
	int calculate(double f(double x));
	 ~Bullet();
};

