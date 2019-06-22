#pragma once
#include "ship.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class Player : public ship
{
private:
public:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	
	Player();
	Player(const char *filename, int radius, int health);
	Player(const char *filename, int radius, int s, int health);
	void calculatePosition();
	void DrawPlayer(int x, int y, int rotation = 0, int scale = 1);
	void CalculateCollisionsForPlayer(Bullets *bullets);
	void PlayerShot(Bullets *bullets);
	double GetX();
	double GetY();
	~Player();
};

