#pragma once
#include "HitboxTypeEnum.h"
#include <math.h>
#include <memory>
class Hitbox
{
protected:
	double radius;
	HitboxType type;
	std::unique_ptr<double> posX = std::make_unique<double>();
	std::unique_ptr<double> posY = std::make_unique<double>();

	//double *posX = NULL;
	//double *posY = NULL;
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
	bool CalculateCollision(HitboxType sType, double sPosX, double sPosY, double sRadius);
	virtual ~Hitbox();
};

