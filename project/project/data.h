#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include "Bullets.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
class DATA {

public:

	ALLEGRO_MUTEX *mutex;
	ALLEGRO_COND  *cond;
	Bullets       *Playerbullets, *enemyBullets;
	Player		  *player;
	std::vector < Enemy * > enemies;

	bool           ready;
	DATA(Bullets *Playerbullets, Bullets *enemyBullets, Player *player);
	//vector of enemies should be put into its own class
	void AddEnemy(const char *filename, int x, int y, double speed, int period);
	void AddEnemy(const char *filename, int x, int y, double speed, double(*f2)(double x), int period);
	void DrawEnemies();
	void calculateEnemies(int timer);
	void ClearDeadEnemies();

	~DATA();

};