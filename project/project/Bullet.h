#pragma once
#include "Config.h"
class Bullet
{
private:
	double rotation;
	double posX;
	double posY;
	double speedX;
	double speedY;
public:
	Bullet(double rotation, double posX, double posY, double speedX, double speedY);
	double GetX();
	double GetY();
	double GetRotation();
	int calculate();
	~Bullet();
};

