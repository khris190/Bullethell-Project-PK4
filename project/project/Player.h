#pragma once
#include "ship.h"
#include "Config.h"
#include "Bullets.h"
#include "Weapons.h"
class Player : public ship
{
private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool shooting = false;

public:	
	
	//Player();
	Player(const char *filename, int radius, int health);
	Player(const char *filename, int radius, int s, int health);
	void calculatePosition();
	void DrawPlayer(int x, int y, int rotation = 0, int scale = 1);
	bool CalculateCollisionsForPlayer(Bullets *bullets);
	void PlayerShot(Bullets *bullets, int counter);
	void SetUp(bool var);
	void SetDown(bool var);
	void SetLeft(bool var);
	void SetRight(bool var);
	void SetShooting(bool var);
	double GetX();
	double GetY();
	~Player();
};

