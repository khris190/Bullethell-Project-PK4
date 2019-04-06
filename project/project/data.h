#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include "Bullets.h"
#include "Player.h"
class DATA {

public:

	ALLEGRO_MUTEX *mutex;
	ALLEGRO_COND  *cond;
	Bullets       *bullets;
	Player		  *player;
	bool           ready;
	bool           ready2;
	void RefrestData (Bullets *bullets);
	DATA(Bullets *bullets, Player *player);

	~DATA();

};