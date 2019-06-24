#pragma once
#include "MyBitmap.h"
#include "Bullet.h"
#include "Object.h"
#include <vector>
class Bullets : public Object
{
			
public:
	std::vector < Bullet * >bullets;
	int damage;
	void* movFunction;
	double(*f)(double);


	Bullets(const char *filename, double(*f)(double));
	Bullets(const char *filename);
	Bullets();
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY);
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX);
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX, double sizeY);
	void setDmg(int value);
	void CalculateBullets();
	void CalculateBulletsV2(double f2(double x));
	void CalcuclateBulletsCollision(double posX, double posY, int objBouncerX, int objBouncerY);
	int CalcuclateBulletsCollision(Hitbox *hitbox);
	void ClearBulletsByCollision();
	void DrawBullets(float scale = 1);
	void DrawBulletstest(float scale = 1);

	std::vector < Bullet * > *GetBullets();
	~Bullets();
};

