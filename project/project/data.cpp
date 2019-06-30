#include "data.h"

DATA::DATA(Bullets *Playerbullets, Bullets *enemyBullets, Player *player)
{
	//mutex = al_create_mutex();
	//cond = al_create_cond();
	this->Playerbullets = Playerbullets;
	this->enemyBullets = enemyBullets;
	this->player = player;
	ready = false;
	counter = 0;
}

void DATA::AddEnemy(const char *filename, int x, int y, double speed, int period) {

	Enemy * enemy = new Enemy(filename, x, y, speed, period);
	enemies.push_back(enemy);
}

void DATA::AddEnemy(const char *filename, int x, int y, double speed, double(*f2)(double x), int period) {

	Enemy * enemy = new Enemy(filename, x, y, speed, f2, period);
	enemies.push_back(enemy);
}

void DATA::calculateEnemies(int timer)
{
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->calculatePosition();
		enemies[i]->CalculateCollisions(Playerbullets);
		enemies[i]->EntityShot(enemyBullets, timer);
	}
}

void DATA::DrawEnemies()
{
	{
		for (unsigned int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->DrawEntity(enemies[i]->GetX(), enemies[i]->GetY(), PI);
		}
	}
}

void DATA::ClearDeadEnemies() {

	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->GetHealthAndBoundarys() <= 0)
		{
			enemies.DeleteElement(i);
		}
	}

}



DATA::~DATA() {
	//al_destroy_mutex(mutex);
	//al_destroy_cond(cond);
}