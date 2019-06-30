#pragma once
#include "MyBitmap.h"
#include "Bullet.h"
#include "Object.h"
#include "TemplateVector.h"

class Bullets : public Object
{
#define Vbullets vector.Vector
public:
	//std::vector < Bullet * >bullets;
	TemplateVector<Bullet*> vector;
	
	int damage;
	//void* movFunction;
	double(*f)(double);

	//Bullets();
	Bullets(const char *filename);
	Bullets(const char *filename, double(*f)(double));
	
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY);
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX);
	void AddBullet(double rotation, double posX, double posY, double speedX, double speedY, double sizeX, double sizeY);
	void setDmg(int value);
	void CalculateBullets();
	void CalculateBulletsWithFunction();
	void CalculateBulletsWithFunction(double f2(double x));
	int CalcuclateBulletsCollision(Hitbox *hitbox);
	void DrawBullets(float scale = 1);

	std::vector < Bullet * > *GetBullets();
	~Bullets();
};

