#include "bullets.h"


Bullets::Bullets(const char *filename) : Object::Object(filename)
{
}

Bullets::Bullets(const char *filename, double(*f)(double)) : Object::Object(filename)
{
	this->f = f;
}

void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY)
{
	Bullet * bullet = new Bullet(rotation, posX, posY, speedX, speedY);
	vector.push_back(bullet);
}
void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX)
{
	Bullet * bullet = new Bullet(rotation, posX, posY, speedX, speedY, sizeX);
	vector.push_back(bullet);
}
void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX, double sizeY)
{
	Bullet * bullet = new Bullet(rotation, posX, posY, speedX, speedY, sizeX, sizeY);
	vector.push_back(bullet);
}

void Bullets::setDmg(int value)
{
	this->damage = value;
}


void Bullets::CalculateBullets()
{
	
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (!(vector[i]->calculate()))
		{
			vector.DeleteElement(i);
		}
	}

}

void Bullets::CalculateBulletsWithFunction()
{

	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (!(vector[i]->calculate(this->f)))
		{
			vector.DeleteElement(i);
		}
	}

}

void Bullets::CalculateBulletsWithFunction(double f2(double x))
{

	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (!(vector[i]->calculate(f2)))
		{
			vector.DeleteElement(i);
		}
	}

}

int Bullets::CalcuclateBulletsCollision(Hitbox *hitbox)
{
	int result = 0;
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (vector[i]->CalculateCollision(hitbox))
		{
			vector.DeleteElement(i);
			result++;
		}
	}
	return result;
}



void Bullets::DrawBullets(float scale)
{
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (i < vector.size())
		{
			DrawObject((int)vector[i]->GetX(), (int)vector[i]->GetY(), vector[i]->GetRotation(), scale);
		}
		
	}
}

std::vector < Bullet *> *Bullets::GetBullets()
{
	return &vector.Vector;
}

Bullets::~Bullets()
{

}
