#pragma once
#include "ship.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class Enemy :
	public ship
{
protected:
	double rotation;
	int period;
	double startX, startY;
	double (*f)(double a);

	//Weapons *playerWeapons = NULL;
public:
	Enemy(const char *filename, int x, int y, double speed, int period);
	Enemy(const char *filename, int x, int y, double speed, double(*f2)(double x), int period);

	void calculatePosition();
	void DrawEntity(int x, int y, double rotation = 0, int scale = 1);
	void EntityShot(Bullets *bullets, int timer);
	double GetHealth();
	double GetHealthAndBoundarys();
	double GetX();
	double GetY();
	//Enemy();
	~Enemy();
};

