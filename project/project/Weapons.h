#pragma once
#include "bullets.h"
#include "SideEnum.h"
class Weapons
{
protected:
	std::vector < Bullets *> weapons;
	Side side;
public:

	Weapons(Side side);
	void AddWeapon(const char *filename);
	~Weapons();
};

