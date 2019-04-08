#include "data.h"

DATA::DATA(Bullets *bullets, Player *player)
{
	mutex = al_create_mutex();
	cond = al_create_cond();
	this->bullets = bullets;
	this->player = player;
	ready = false;
}
void DATA::RefrestData(Bullets *bullets)
{
	this->bullets = bullets;
}

DATA::~DATA() {
	al_destroy_mutex(mutex);
	al_destroy_cond(cond);
}