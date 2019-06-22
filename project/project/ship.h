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
		int health;
		Weapons *playerWeapons = NULL;
public:
	ship();
	ship(const char *filename, int x, int y, int radius, int health);
	ship(const char *filename, int x, int y, int radius, int s, int health);
	void calculatePosition();
	void ShipShotShot(Bullets *bullets);
	bool CalculateCollisions(Bullets *bullets);

	double GetX();
	double GetY();
	double GetSpeed();
	~ship();

protected:
	void DrawShip(int x, int y, int rotation = 0, int scale = 1);
	
};

