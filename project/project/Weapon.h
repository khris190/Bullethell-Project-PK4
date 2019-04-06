#pragma once
#include "Bullets.h"
class Weapon :
	public Bullets
{
public:
	Weapon(const char *filename);
	~Weapon();
};

