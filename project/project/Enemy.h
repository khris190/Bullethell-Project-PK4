#pragma once
#include "ship.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class Enemy :
	public ship
{
private:
	int rotation;
	double speed;
	double health;
	Weapons *playerWeapons = NULL;
public:

	void calculatePosition(double offsetX, double offsetY, double xCubed, double xScuared, double x);
	void DrawEntity(int x, int y, int rotation = 0, int scale = 1);
	void EntityShot(Bullets *bullets);
	double GetHealth();
	double GetX();
	double GetY();
	Enemy();
	Enemy(const char *filename, int x, int y, double speed);
	~Enemy();
};

