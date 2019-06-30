#pragma once
#include "Object.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class ship : public Object
{
protected:
	double rotation;
		double speed;
		int health;
		//Weapons *playerWeapons = NULL;

		void DrawShip(int x, int y, int rotation = 0, int scale = 1);
public:
	//ship();
	ship(const char *filename, int x, int y, int radius, int health);
	ship(const char *filename, int x, int y, int radius, double s, int health);
	//void calculatePosition();
	//void ShipShotShot(Bullets *bullets);
	bool CalculateCollisions(Bullets *bullets);
	int GetHealth();
	double GetX();
	double GetY();
	double GetSpeed();
	~ship();

};

