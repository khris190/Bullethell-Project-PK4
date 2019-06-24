#include "Player.h"


Player::Player() : ship::ship()
{
}

Player::Player(const char *filename, int radius, int health) : ship::ship(filename, WindowWidth / 2, WindowHeight - 32, radius, health)
{
}

Player::Player(const char *filename, int radius, int s, int health) : ship::ship(filename, WindowWidth / 2, WindowHeight - 32, radius, s, health)
{
}

double Player::GetX()
{
	return *posX;
}	
double Player::GetY()
{	
	return *posY;
}

void Player::calculatePosition()
{
	if (up && !down)
	{
		if (left && !right)
		{
			if (*posX > 0)
			{
				*posX -= GetSpeed() * 0.71;
			}
			if (*posY > 0)
			{
				*posY -= GetSpeed() * 0.71;
			}
			
		}
		else if (right && !left)
		{
			if (*posX < WindowWidth)
			{
				*posX += GetSpeed() * 0.71;
			}
			if (*posY > 0)
			{
				*posY -= GetSpeed() * 0.71;
			}
		}
		else
		{
			if (*posY > 0)
			{
				*posY -= GetSpeed();
			}
		}
		
	}
	else if (down && !up)
	{
		if (left && !right)
		{
			if (*posY < WindowHeight)
			{
				*posY += GetSpeed() * 0.71;
			}
			if (*posX > 0)
			{
				*posX -= GetSpeed() * 0.71;
			}
		}
		else if (right && !left)
		{
			if (*posY < WindowHeight)
			{
				*posY += GetSpeed() * 0.71;
			}
			if (*posX < WindowWidth)
			{
				*posX += GetSpeed() * 0.71;
			}
		}
		else
		{
			if (*posY < WindowHeight)
			{
				*posY += GetSpeed();
			}
		}
	}
	else if (left && !right)
	{
		if (*posX > 0)
		{
			*posX -= GetSpeed();
		}
	}
	else if (right && !left)
	{
		if (*posX < WindowWidth)
		{
			*posX += GetSpeed();
		}
	}
}

bool Player::CalculateCollisionsForPlayer(Bullets *bullets)
{
	if (CalculateCollisions(bullets))
	{
		return 1;
	}
	return 0;
	
}

void Player::PlayerShot(Bullets *bullets)
{
	bullets->AddBullet(0, GetX() - 1, GetY() - 10, 0, -3, 3);
}

void Player::DrawPlayer(int x, int y, int rotation, int scale)
{
	DrawShip(x, y, rotation, scale);
}

Player::~Player()
{
}
