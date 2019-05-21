#pragma once
#include "Object.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class Enemy :
	public Object
{
private:
	int rotation;
	double speedX;
	double speedY;
	double health;
	Weapons *playerWeapons = NULL;
public:

	void calculatePosition();
	void DrawPlayer(int x, int y, int rotation = 0, int scale = 1);
	void CalculateCollisions();
	void PlayerShot(Bullets *bullets);
	double GetX();
	double GetY();
	Enemy();
	Enemy(const char *filename, int x, int y, double speedX, double speedY);
	~Enemy();
};

