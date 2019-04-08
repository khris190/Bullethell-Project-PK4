#pragma once
#include "HitboxTypeEnum.h"
#include <math.h>
class Hitbox
{
private:
	
	
	double radius;
	HitboxType type;
protected:
	double *posX = NULL;
	double *posY = NULL;
public:
	double boundryX;
	double boundryY;
	Hitbox();
	Hitbox(double x, double y);
	Hitbox(double x, double y, double radius);
	Hitbox(double x, double y, double boundryX, double boundryY);
	void HitboxHELPME(double x, double y, bool flag);
	double GetX();
	double GetY();
	bool CalculateCollision(Hitbox *second);
	virtual ~Hitbox();
};

