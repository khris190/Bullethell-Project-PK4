#include "Game.h"

Game::Game()
{
	result = mainloop();
}


int Game::mainloop()	
{
#pragma region INIT

	ALLEGRO_DISPLAY * display = nullptr;

#pragma region basicAllegroINIT

	if (!al_init())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_primitives_addon())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro primitives addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

#pragma endregion

#pragma region imageAddon

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

#pragma endregion
	
#pragma region fonts

	if (!al_init_font_addon())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro fonts addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_init_ttf_addon())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro ttf addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	ALLEGRO_FONT *font = al_load_ttf_font("Resources/fonts/Roboto-Light.ttf", 36, 0);

	if (!font) {
		return 1;
	}

#pragma endregion

#pragma region display


	display = al_create_display(WindowWidth, WindowHeight);

	if (display == nullptr)
	{
		std::cerr << "Well, something is not working..." << std::endl;
		al_rest(5.0);
		return -3;
	}

#pragma endregion

#pragma region eventQueue

	ALLEGRO_EVENT_QUEUE * queue = NULL;
	ALLEGRO_EVENT ev1;
	queue = al_create_event_queue();
	if (queue == NULL)
	{
		fprintf(stderr, "Failed to create event queue!\n");
		return -2;
	}
	al_register_event_source(queue, al_get_display_event_source(display));
#pragma endregion

#pragma region CONTROLS

	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());

#pragma endregion

#pragma region timer

	ALLEGRO_TIMER * timer = nullptr;
	timer = al_create_timer(1.0 / FPScount);
	if (!timer)
	{
		fprintf(stderr, "Failed to create FPS timer!\n");
		return -1;
	}
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

#pragma endregion

#pragma region objects



	Player player("Resources/space_breaker_asset/Ships/Small/body_01.png", 8, 8, PlayerHealth);
	if (player.GetBitmap() == NULL)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize playah!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	Bullets PlayerBullets("Resources/shot.bmp", sin);
	if (PlayerBullets.GetBitmap() == NULL)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize bulletsboiz!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	PlayerBullets.setDmg(PlayerDmg);

	Bullets EnemyBullets("Resources/shot1.png");
	if (EnemyBullets.GetBitmap() == NULL)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize bulletsboizv2!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	EnemyBullets.setDmg(2);

	Object pause("Resources/pausesmall.png");

#pragma endregion	

#pragma region testfbulletspawn

	for (int i = 0; i < 20; i++)
	{
		for (int y = 0; y < 20; y++)
		{

			//PlayerBullets.AddBullet(PI, 8 * i + 10, 9 * y, 0, 2, 2);
			//bulletsV2.AddBullet(0, 4 * i + 10, 3 * y, 0, 1, 2);

		}
	}

	//for (int i = 0; i < 400; i++)
	//{
	//	for (int y = 0; y < 500; y++)
	//	{

	//		//basicBullets.AddBullet(0, 10 * i + 10, 4 * y, 0, 1, 2);
	//		bulletsV2.AddBullet(0, 2 * i + 10, 2 * y, 0, 1, 2);

	//	}
	//}

#pragma endregion

#pragma region threads

	ALLEGRO_THREAD      *thread_1 = NULL;
	DATA gameData(&PlayerBullets, &EnemyBullets, &player);

	thread_1 = al_create_thread(Func_ThreadBulletsCalculations, &gameData);

	al_start_thread(thread_1);

#pragma endregion

#pragma region testEnemiesSpawn

	//gameData.AddEnemy("Resources/space_breaker_asset/Ships/Small/body_02.png", WindowWidth / 2, 32, 0.5, [](double a) { return sin(a - PI / 2); }, 30);
	//gameData.AddEnemy("Resources/space_breaker_asset/Ships/Small/body_02.png", WindowWidth *2 / 3, 32, 1, [](double a) { return sin(a - PI / 2); }, 30);
	//gameData.AddEnemy("Resources/space_breaker_asset/Ships/Small/body_02.png", WindowWidth / 3, 32, 1.5, [](double a) { return sin(a - PI / 2); }, 30);



#pragma endregion


#pragma endregion

#pragma region setVariables

	al_set_app_name(programName);

	bool done = false;
	bool doloop = true;
	bool playerDead = false;
	bool mauseInPasueButton = false;
	bool mauseInDisplay = true;

#pragma endregion
	
#pragma region MAINLOOP
	try
	{
	while (!done)
	{
		al_wait_for_event(queue, &ev1);
		ALLEGRO_MOUSE_STATE state;
		
		switch (ev1.type)
		{

#pragma region ALLEGRO_EVENT_DISPLAY_CLOSE

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;

#pragma endregion

#pragma region allegro event timer

		case ALLEGRO_EVENT_TIMER: /* Dla eventu od timera, odœwierz display */

			if (playerDead)
			{
				al_get_mouse_state(&state);
				if (state.x < WindowWidth / 2 + 80 && state.x > WindowWidth / 2 - 80 && state.y < WindowHeight / 2 + 100 && state.y > WindowHeight / 2 - 100)
				{

					mauseInPasueButton = true;
					pause.ChangeBitmap("Resources/pauseACTIVEsmall.png");
				}
				else if (state.x < WindowWidth / 2 + 100 && state.x > WindowWidth / 2 - 100 && state.y < WindowHeight / 2 + 80 && state.y > WindowHeight / 2 - 80)
				{
					mauseInPasueButton = true;
					pause.ChangeBitmap("Resources/pauseACTIVEsmall.png");
				}
				else
				{
					mauseInPasueButton = false;
					pause.ChangeBitmap("Resources/pausesmall.png");
				}
				al_draw_scaled_rotated_bitmap(pause.GetBitmap(), 128, 128, WindowWidth / 2, WindowHeight / 2, 1, 1, 0, 0);
				al_flip_display();
			}
			else
			{
				if (doloop)
				{
					
					gameData.ready = true;
					player.calculatePosition();

					gameData.enemyBullets->CalculateBullets();
					if (gameData.player->CalculateCollisionsForPlayer(gameData.enemyBullets))
					{
						playerDead = true;
					}

					player.PlayerShot(&PlayerBullets, gameData.counter);
					while (gameData.ready)
					{
						al_rest(0.001);
					}
				}
				if (doloop && al_is_event_queue_empty(queue))
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));

#pragma region draw
					al_hold_bitmap_drawing(true);

					player.DrawPlayer(player.GetX(), player.GetY());
					gameData.DrawEnemies();

					PlayerBullets.DrawBullets(1);
					EnemyBullets.DrawBullets(0.5);

					std::string test = std::to_string(player.GetHealth());
					const char* text = test.c_str();
					al_draw_text(font, al_map_rgb(255, 255, 255),30, WindowHeight-50, ALLEGRO_ALIGN_CENTRE, text);


					al_hold_bitmap_drawing(false);
#pragma endregion

					al_flip_display();
				}

				else if (mauseInDisplay&& al_is_event_queue_empty(queue))
				{
					al_get_mouse_state(&state);
					if (state.x < WindowWidth / 2 + 80 && state.x > WindowWidth / 2 - 80 && state.y < WindowHeight / 2 + 100 && state.y > WindowHeight / 2 - 100)
					{

						mauseInPasueButton = true;
						pause.ChangeBitmap("Resources/pauseACTIVEsmall.png");
					}
					else if (state.x < WindowWidth / 2 + 100 && state.x > WindowWidth / 2 - 100 && state.y < WindowHeight / 2 + 80 && state.y > WindowHeight / 2 - 80)
					{
						mauseInPasueButton = true;
						pause.ChangeBitmap("Resources/pauseACTIVEsmall.png");
					}
					else
					{
						mauseInPasueButton = false;
						pause.ChangeBitmap("Resources/pausesmall.png");
					}
					al_draw_scaled_rotated_bitmap(pause.GetBitmap(), 128, 128, WindowWidth / 2, WindowHeight / 2, 1, 1, 0, 0);
					al_flip_display();
				}
			}
			break;
#pragma endregion

#pragma region allegro event mouse button down

		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

			al_get_mouse_state(&state);
			if (state.buttons & 1 && mauseInPasueButton == true)
			{
				doloop = true;
				mauseInPasueButton = false;
			}
			else if (state.buttons & 1 && doloop)
			{
				EnemyBullets.AddBullet(PI, state.x, state.y, 0, 1, 8);
			}
			break;
#pragma endregion

#pragma region keyboard

		case ALLEGRO_EVENT_KEY_DOWN:

			switch (ev1.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				player.SetUp(true);
				break;
			case ALLEGRO_KEY_S:
				player.SetDown(true);
				break;
			case ALLEGRO_KEY_A:
				player.SetLeft(true);
				break;
			case ALLEGRO_KEY_D:
				player.SetRight(true);
				break;
			case ALLEGRO_KEY_SPACE:
				player.SetShooting(true);
				break;
			default:
				break;
			};
			break;
		case ALLEGRO_EVENT_KEY_UP:
			switch (ev1.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				player.SetUp(false);
				break;
			case ALLEGRO_KEY_S:
				player.SetDown(false);
				break;
			case ALLEGRO_KEY_A:
				player.SetLeft(false);
				break;
			case ALLEGRO_KEY_D:
				player.SetRight(false);
				break;

			case ALLEGRO_KEY_1:
				for (int i = 0; i < 40; i++)
				{
					for (int y = 0; y < 40; y++)
					{

						//basicBullets.AddBullet(0, 0 + 10 * i + 10, 800 - 10 * y, 0, 0, 8);
						EnemyBullets.AddBullet(0, 0 + 15 * i + 10, 15 * y, 0, 11, 8);

					}
				}
				break;
			case ALLEGRO_KEY_SPACE:
				player.SetShooting(false);
				break;
			default:
				break;
			}
				break;

#pragma endregion

#pragma region displayEvents

#ifndef NOPAUSE
		case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
			al_stop_timer(timer);
			doloop = false;
			break;
		case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
			al_start_timer(timer);
			break;
		case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
			mauseInDisplay = false;
			doloop = false;
			pause.ChangeBitmap("Resources/pausesmall.png");
			al_draw_scaled_rotated_bitmap(pause.GetBitmap(), 128, 128, WindowWidth / 2, WindowHeight / 2, 1, 1, 0, 0);
			al_flip_display();
			break;
		case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
			mauseInDisplay = true;
			break;
#endif // NOPAUSE

#pragma endregion

		default: break;
		}
	}
	}
	catch (const std::exception& thing)
	{
		al_show_native_message_box(display, "Error", "Error", thing.what() ,
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		
	}

#pragma endregion

#pragma region deconstructors

	al_destroy_thread(thread_1);

	al_uninstall_keyboard();
	al_uninstall_mouse();

	al_destroy_display(display);
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
	al_shutdown_font_addon();
#pragma endregion

	return 0;
}

void *Game::Func_ThreadBulletsCalculations(ALLEGRO_THREAD *thr, void *arg)
{
	DATA *data = (DATA*)arg;
	while (!al_get_thread_should_stop(thr))
	{
		data->counter++;
		data->counter = data->counter % 1800;
		while (!data->ready)
		{
			al_rest(0.001);
			if (al_get_thread_should_stop(thr))
			{
				return 0;
			}
		}
		//data->Playerbullets->CalculateBullets();
		
		data->Playerbullets->CalculateBulletsWithFunction([](double a) { return a * 0; });
		data->calculateEnemies(data->counter);
		data->ClearDeadEnemies();


		if (data->counter % TicsForEnemySpawn == 0)
		{
			data->AddEnemy("Resources/space_breaker_asset/Ships/Small/body_02.png",
				(rand() % (WindowWidth - 64)) + 32, 
				32, 
				(double)((rand() % 100)+50)/100, [](double a) { return sin(a - PI / 2); }, 
				30);
		}
			
		data->ready = false;
	}

	//data->bullets->ClearBulletsByCollision();

	return 0;
}

Game::~Game()
{
}
