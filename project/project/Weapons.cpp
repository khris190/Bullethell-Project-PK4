#include "Weapons.h"



Weapons::Weapons(Side side)
{
	this->side = side;
}

void Weapons::AddWeapon(const char *filename)
{
	Bullets * weapon = new Bullets(filename);
	weapons.push_back(weapon);
}


Weapons::~Weapons()
{
	while (weapons.size() > 0)
	{
		Bullets *swapper = weapons[0];
		weapons[0] = weapons[weapons.size() - 1];
		weapons[weapons.size() - 1] = swapper;
		weapons.erase(weapons.end() - 1);
		delete swapper;
	}
}
