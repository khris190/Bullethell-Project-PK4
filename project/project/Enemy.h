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
	int period;
	Weapons *playerWeapons = NULL;
public:

	void calculatePosition(double offsetX, double offsetY, double xCubed, double xScuared, double x);
	void DrawEntity(int x, int y, double rotation = 0, int scale = 1);
	void EntityShot(Bullets *bullets, int timer);
	double GetHealth();
	double GetX();
	double GetY();
	Enemy();
	Enemy(const char *filename, int x, int y, double speed, int period);
	~Enemy();
};

