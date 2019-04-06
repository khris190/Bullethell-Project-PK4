#include "Game.h"

Game::Game()
{
	result = mainloop();
}

int Game::mainloop()	
{
#pragma region inicjalizacja

	ALLEGRO_DISPLAY * display = nullptr;

	if (!al_init())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	
#pragma region imageAddon

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
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

#pragma region objects

	Bullets basicBullets("C:/Users/User/source/repos/Bullethell-Project-PK4/project/project/Resources/shot.bmp");
	if (basicBullets.GetBitmap() == NULL)
	{
		return -1;
	}
	Player player("Resources/space_breaker_asset/Ships/Small/body_01.png", 16, 16);
	if (player.GetBitmap() == NULL)
	{
		return -1;
	}
	Bullets bulletsV2("Resources/shot1.png");
	if (bulletsV2.GetBitmap() == NULL)
	{
		return -1;
	}

	ALLEGRO_THREAD      *thread_1 = NULL;
	ALLEGRO_THREAD      *thread_2 = NULL;


	Object pause("Resources/pausesmall.png");
#pragma endregion	
	
	al_set_app_name(programName);
	al_register_event_source(queue, al_get_display_event_source(display));
#pragma endregion
	
		
#pragma region mainloop
	
	al_start_timer(timer);
#pragma region threads

	DATA basicBulletsData(&basicBullets, &player);
	DATA bulletsV2Data(&bulletsV2, &player);
	thread_1 = al_create_thread(Func_ThreadBulletsCalculations, &basicBulletsData);
	thread_2 = al_create_thread(Func_ThreadBulletsCalculations, &bulletsV2Data);
	al_start_thread(thread_1);
	al_start_thread(thread_2);
#pragma endregion
#pragma region testfbulletspawn

	for (int i = 0; i < 30; i++)
	{
		for (int y = 0; y < 30; y++)
		{
			basicBullets.AddBullet(0, 0 + 20 * i, 800 - 20 * y, 0, -1.5);
			bulletsV2.AddBullet(0, 0 + 20 * i + 10, 800 - 20 * y, 0, -1);

		}
	}
#pragma endregion



	bool done = false;
	bool doloop = true;
	bool mauseInPasueButton = false;
	bool mauseInDisplay = true;
	while (!done)
	{
		al_wait_for_event(queue, &ev1);
		ALLEGRO_MOUSE_STATE state;
		
		/* Je¿eli pojawi siê event, wybierz co nale¿y wykonaæ */
		switch (ev1.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;

#pragma region allegro event timer

		case ALLEGRO_EVENT_TIMER: /* Dla eventu od timera, odœwierz display */

			if (doloop)
			{
				player.calculatePosition();
				basicBulletsData.ready = true;
				bulletsV2Data.ready = true;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				while (!basicBulletsData.ready2)
				{
					al_rest(0.005);
				}
				while (!bulletsV2Data.ready2)
				{
					al_rest(0.005);
				}

				player.DrawPlayer(player.GetX(), player.GetY());

#pragma region bulletdraw
				basicBullets.DrawBullets(2);
				bulletsV2.DrawBullets();
#pragma endregion
				
				al_flip_display();
			}
			else if (mauseInDisplay)
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
				bulletsV2.AddBullet(PI, state.x, state.y, 0, 1);
			}
			break;
#pragma endregion

#pragma region keyboard

		case ALLEGRO_EVENT_KEY_DOWN:

			switch (ev1.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				player.up = true;
				break;
			case ALLEGRO_KEY_S:
				player.down = true;
				break;
			case ALLEGRO_KEY_A:
				player.left = true;
				break;
			case ALLEGRO_KEY_D:
				player.right = true;
				break;
			default:
				break;
			};
			break;
		case ALLEGRO_EVENT_KEY_UP:
			switch (ev1.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				player.up = false;
				break;
			case ALLEGRO_KEY_S:
				player.down = false;
				break;
			case ALLEGRO_KEY_A:
				player.left = false;
				break;
			case ALLEGRO_KEY_D:
				player.right = false;
				break;
			default:
				break;
			}
				break;

#pragma endregion



		case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
			//doloop = false;
			break;
		case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
			//mauseInDisplay = false;
			//doloop = false;
			break; 
		case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
			mauseInDisplay = true;
			break;
			
		default: break;
		}
	}
#pragma endregion


#pragma region deconstructors

	al_destroy_thread(thread_1);
	al_destroy_thread(thread_2);

	al_destroy_display(display);
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
	al_shutdown_image_addon();
#pragma endregion
	return 0;
}

void *Game::Func_ThreadBulletsCalculations(ALLEGRO_THREAD *thr, void *arg)
{

	DATA *data = (DATA*)arg;
	//moze while(1)
	while (!al_get_thread_should_stop(thr))
	{
		while (!data->ready)
		{
			al_rest(0.005);
			if (al_get_thread_should_stop(thr))
			{
				return 0;
			}
		}
		data->bullets->CalculateBullets();
		data->bullets->CalcuclateBulletsCollision(data->player->GetX(), data->player->GetY(), data->player->bouncerX, data->player->bouncerY);
		data->ready = false;
		data->ready2 = true;

	}

	return 0;
}

Game::~Game()
{
}
