#pragma once
#include "Object.h"
#include "Config.h"
#include "Bullets.h"
class Player : public Object
{
private:
	int rotation;
	double speed;
	double health;
public:

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	
	Player();
	Player(const char *filename, int x, int y);
	void calculatePosition();
	void DrawPlayer(int x, int y, int rotation = 0, int scale = 1);
	void CalculateCollisions();
	void PlayerShot(Bullets *bullets);
	double GetX();
	double GetY();
	~Player();
};

