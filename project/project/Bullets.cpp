#include "Bullets.h"



Bullets::Bullets(const char *filename) : Object::Object(filename)
{
}

Bullets::Bullets()
{}

void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY)
{
	Bullet * bullet = new Bullet(rotation, posX, posY, speedX, speedY);
	bullets.push_back(bullet);
}
void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX)
{
	Bullet * bullet = new Bullet(rotation, posX, posY, speedX, speedY, sizeX);
	bullets.push_back(bullet);
}
void Bullets::AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX, double sizeY)
{
	Bullet * bullet = new Bullet(rotation, posX, posY, speedX, speedY, sizeX, sizeY);
	bullets.push_back(bullet);
}


void Bullets::CalculateBullets()
{
	
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		if (!(bullets[i]->calculate()))
		{
			Bullet *swapper = bullets[i];
			bullets[i] = bullets[bullets.size() - 1];
			bullets[bullets.size() - 1] = swapper;
			bullets.erase(bullets.end() - 1);
			delete swapper;
		}
	}

}

void Bullets::CalcuclateBulletsCollision(double posX, double posY, int objBouncerX, int objBouncerY)
{
	
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		if (CollisionCalculate(bullets[i]->GetX(), bullets[i]->GetY(), posX, posY, objBouncerX, objBouncerX))
		{
			bullets[i] = bullets[bullets.size() - 1];
			bullets.erase(bullets.end() - 1);
		}
	}
}
void Bullets::CalcuclateBulletsCollision(Hitbox *hitbox)
{
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->CalculateCollision(hitbox))
		{
			Bullet *swapper = bullets[i];
			bullets[i] = bullets[bullets.size() - 1];
			bullets[bullets.size() - 1] = swapper;
			bullets.erase(bullets.end() - 1);
			delete swapper;
		}
	}
}

void Bullets::ClearBulletsByCollision()
{
}


void Bullets::DrawBullets(float scale)
{
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		if (i < bullets.size())
		{
			DrawObject((int)bullets[i]->GetX(), (int)bullets[i]->GetY(), bullets[i]->GetRotation(), scale);
		}
		
	}
}
void Bullets::DrawBulletstest(float scale)
{
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		DrawObjecttest(bullets[i]->GetX(), bullets[i]->GetY(), bullets[i]->GetRotation(), scale);
	}
}
std::vector < Bullet *> *Bullets::GetBullets()
{
	return &bullets;
}

Bullets::~Bullets()
{
	while (bullets.size() > 0)
	{
		Bullet *swapper = bullets[0];
		bullets[0] = bullets[bullets.size() - 1];
		bullets[bullets.size() - 1] = swapper;
		bullets.erase(bullets.end() - 1);
		delete swapper;
	}
}
