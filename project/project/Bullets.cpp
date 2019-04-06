#include "Bullets.h"



Bullets::Bullets(const char *filename) : Object::Object(filename)
{
}

Bullets::Bullets()
{}


void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY)
{
	Bullet bullet(rotation, posX, posY, speedX, speedY);
	bullets.push_back(bullet);
}


void Bullets::CalculateBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!(bullets[i].calculate()))
		{
			bullets[i] = bullets[bullets.size() - 1];
			bullets.erase(bullets.end() - 1);
		}
	}
}

void Bullets::CalcuclateBulletsCollision(double posX, double posY, int objBouncerX, int objBouncerY)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (CollisionCalculate(bullets[i].GetX(), bullets[i].GetY(), posX, posY, objBouncerX, objBouncerX))
		{
			bullets[i] = bullets[bullets.size() - 1];
			bullets.erase(bullets.end() - 1);
		}
	}
}


void Bullets::DrawBullets(int scale)
{
	int i = 0;
	while (i < bullets.size())
	{
		DrawObject(bullets[i].GetX(), bullets[i].GetY(), bullets[i].GetRotation(), scale);
		i++;
	}
}

std::vector < Bullet > *Bullets::GetBullets()
{
	return &bullets;
}

Bullets::~Bullets()
{

}
