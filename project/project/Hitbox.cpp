#include "Hitbox.h"


Hitbox::Hitbox(double x, double y)
{
	*posX = x;
	*posY = y;
	type = dot;
}
Hitbox::Hitbox(double x, double y, double radius)
{
	*posX = x;
	*posY = y;
	this->radius = radius;
	type = circle;
}
Hitbox::Hitbox(double x, double y, double boundryX, double boundryY)
{
	*posX = x;
	*posY = y;
	this->boundryX = boundryX;
	this->boundryY = boundryY;
	type = square;
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

bool Hitbox::CalculateCollision(HitboxType sType, double sPosX, double sPosY, double sRadius)
{
	if (type == dot)
	{
		/*if (second.type == dot){}else*/
		if (sType == circle)
		{
			return false;
		}
		else if (type == square)
		{
			return false;
		}
		else
		{
			if (*posX == sPosX && *posY == sPosY)
			{
				return true;
			}
			return false;
		}

	}
	else if (type == circle)
	{

		if (sType == dot)
		{
			if (*(this->posX) < sPosX + this->radius
				&& *(this->posX) > sPosX - this->radius
				&&*(this->posY) < sPosY + this->radius
				&&*(this->posY) > sPosY - this->radius)
			{
				if (pow(*(this->posX) - sPosX, 2) + pow(*(this->posY) - sPosY, 2) <= pow(this->radius, 2))
				{
					return true;
				}
			}
			return false;
		}
		else if (sType == circle)
		{
			if (*(this->posX) < sPosX + this->radius + sRadius	
				&& *(this->posX) > sPosX - this->radius - sRadius
				&&*(this->posY) < sPosY + this->radius + sRadius
				&&*(this->posY) > sPosY - this->radius - sRadius)
			{
				if (pow(*(this->posX) - sPosX, 2) + pow(*(this->posY) - sPosY, 2) <= pow(sRadius + this->radius, 2))
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
		if (sType == dot)
		{

		}
		else if (sType == circle)
		{

		}
		else //if (type == square)
		{

		}
	}
}

Hitbox::~Hitbox()
{	
}
	