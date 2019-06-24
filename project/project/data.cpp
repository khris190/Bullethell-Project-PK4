#include "data.h"

DATA::DATA(Bullets *Playerbullets, Bullets *enemyBullets, Player *player)
{
	mutex = al_create_mutex();
	cond = al_create_cond();
	this->Playerbullets = Playerbullets;
	this->enemyBullets = enemyBullets;
	this->player = player;
	ready = false;
}

void DATA::AddEnemy(const char *filename, int x, int y, double speed) {

	Enemy * enemy = new Enemy(filename, x, y, speed);
	enemies.push_back(enemy);
}

void DATA::calculateEnemies()
{
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->CalculateCollisions(Playerbullets);
	}
}

void DATA::ClearDeadEnemies() {

	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->GetHealth() <= 0)
		{
			Enemy *swapper = enemies[i];
			enemies[i] = enemies[enemies.size() - 1];
			enemies[enemies.size() - 1] = swapper;
			enemies.erase(enemies.end() - 1);
			delete swapper;
		}
	}
}



DATA::~DATA() {
	al_destroy_mutex(mutex);
	al_destroy_cond(cond);
}