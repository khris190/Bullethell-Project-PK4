#pragma once
#include "Object.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class ship : public Object
{
private:
	int rotation;
		double speed;
		double health;
		Weapons *playerWeapons = NULL;
public:
	ship();
	ship(const char *filename, int x, int y, int radius);
	ship(const char *filename, int x, int y, int radius, int s);
	void calculatePosition();
	void DrawShip(int x, int y, int rotation = 0, int scale = 1);
	void CalculateCollisions(Bullets *bullets);
	void ShipShotShot(Bullets *bullets);
	double GetX();
	double GetY();
	double GetSpeed();
	~ship();
};

