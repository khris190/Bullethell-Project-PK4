#pragma once
#include "MyBitmap.h"
#include "Bullet.h"
#include "Object.h"
#include <vector>
class Bullets : public Object
{

public:
	std::vector < Bullet > bullets;
	Bullets(const char *filename);
	Bullets();
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY);
	void CalculateBullets();
	void CalcuclateBulletsCollision(double posX, double posY, int objBouncerX, int objBouncerY);
	void DrawBullets(int scale = 1);
	std::vector < Bullet > *GetBullets();
	~Bullets();
};

