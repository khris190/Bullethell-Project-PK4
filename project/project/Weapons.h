#pragma once
#include "Weapon.h"
class Weapons
{
protected:
	std::vector < Bullets > weapons;
public:

	Weapons(const char *filename);
	~Weapons();
};

