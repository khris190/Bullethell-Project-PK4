#include "Player.h"


Player::Player() : Object::Object()
{
	speed = 3;
}
Player::Player(const char *filename, int x, int y) : Object::Object(filename, x, y)
{ 
	this->posX = WindowWidth / 2;
	this->posY = WindowHeight - 32; 
	speed = 3;
}



double Player::GetX()
{
	return posX;
}
double Player::GetY()
{
	return posY;
}




void Player::calculatePosition()
{
	if (up && !down)
	{
		if (left && !right)
		{
			posY -= speed * 0.71;
			posX -= speed * 0.71;
		}
		else if (right && !left)
		{
			posY -= speed * 0.71;
			posX += speed * 0.71;
		}
		else
		{
			posY -= speed;
		}
		
	}
	else if (down && !up)
	{
		if (left && !right)
		{
			posY += speed * 0.71;
			posX -= speed * 0.71;
		}
		else if (right && !left)
		{
			posY += speed * 0.71;
			posX += speed * 0.71;
		}
		else
		{
			posY += speed;
		}
	}
	else if (left && !right)
	{
		posX -= speed;
	}
	else if (right && !left)
	{
		posX += speed;
	}
}

void Player::DrawPlayer(int x, int y, int rotation, int scale)
{
	DrawObject(x, y, rotation, scale);
}

Player::~Player()
{
}
