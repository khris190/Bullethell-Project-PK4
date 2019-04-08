#include "Hitbox.h"

Hitbox::Hitbox()
{
}
Hitbox::Hitbox(double x, double y)
{
	this->posX = new double(x);
	this->posY = new double(y);
	type = dot;
}
Hitbox::Hitbox(double x, double y, double radius)
{
	this->posX = new double(x);
	this->posY = new double(y);
	this->radius = radius;
	type = circle;
}
Hitbox::Hitbox(double x, double y, double boundryX, double boundryY)
{
	this->posX = new double(x);
	this->posY = new double(y);
	this->boundryX = boundryX;
	this->boundryY = boundryY;
	type = square;
}


void Hitbox::HitboxHELPME(double x, double y, bool flag)
{
	if (flag)
	{
		*(this->posX) = x;
		*(this->posY) = y;
	}
	
}
double Hitbox::GetX()
{
	return *posX;
}
double Hitbox::GetY()
{
	return *posY;
}


bool Hitbox::CalculateCollision(Hitbox *second)
{
	if (type == dot)
	{
		/*if (second.type == dot){}else*/ 
		if (second->type == circle)
		{
			return false;
		}
		else if (type == square)
		{
			return false;
		}
		else
		{
			if (*posX == *(second->posX) && *posY == *(second->posY))
			{
				return true;
			}
			return false;
		}
		
	}
	else if (type == circle)
	{
		
		if (second->type == dot)
		{
			if (*(this->posX) < *(second->posX) + this->radius
				&& *(this->posX) > *(second->posX) - this->radius
				&&*(this->posY) < *(second->posY) + this->radius
				&&*(this->posY) > *(second->posY) - this->radius)
			{
				if (pow(*(this->posX) - *(second->posX), 2) + pow(*(this->posY) - *(second->posY), 2) <= pow(this->radius, 2))
				{
					return true;
				}
			}
			return false;
		}
		else if (second->type == circle)
		{
			if (*(this->posX) < *(second->posX) + this->radius + second->radius
				&& *(this->posX) > *(second->posX) - this->radius - second->radius
				&&*(this->posY) < *(second->posY) + this->radius + second->radius
				&&*(this->posY) > *(second->posY) - this->radius - second->radius)
			{
				if (pow(*(this->posX) - *(second->posX), 2) + pow(*(this->posY) - *(second->posY), 2) <= pow(second->radius + this->radius, 2))
				{
					return true;
				}
			}
			return false;
		}
		else //if (type == square)
		{

		}
	}
	else //if (type == square)
	{
		if (second->type == dot)
		{

		}
		else if (second->type == circle)
		{

		}
		else //if (type == square)
		{

		}
	}
}


Hitbox::~Hitbox()
{
	if (posX != NULL)
	{
		delete posX;
	}
	if (posY != NULL)
	{
		delete posY;
	}
	
}
	