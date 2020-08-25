#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../include/game.h"
#include "../include/player.h"

int main()
{
	//initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	t_game* game = create_game();
	if (game == NULL)
		return 1;

	game_renderer(game->renderer);
	bool upPressed = false;
	bool downPressed = false;
	bool rightPressed = false;
	bool leftPressed = false;

	Uint32 time = 0;

	while (game->isProgramRunning)
	{
		//input handling
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				game->isProgramRunning = false;
			}
			//control =  player_input(event, control);
			//player_pos_update(game->snakeHead, control);

			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				{
					rightPressed = true;
					leftPressed = false;
					upPressed = false;
					downPressed = false;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
				{
					rightPressed = false;
					leftPressed = true;
					upPressed = false;
					downPressed = false;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
				{
					rightPressed = false;
					leftPressed = false;
					upPressed = true;
					downPressed = false;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
				{
					rightPressed = false;
					leftPressed = false;
					upPressed = false;
					downPressed = true;
				}
			}
			/*else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				{
					rightPressed = false;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
				{
					leftPressed = false;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
				{
					upPressed = false;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
				{
					downPressed = false;
				}
			}*/
		}

		Uint32 currentTime = SDL_GetTicks();
		float deltaTime = ((float)currentTime - (float)time) / 1000.f;
		time = currentTime;


		//update
		if (rightPressed)
			game->snakeHead->x += 64.f * deltaTime;
		if (leftPressed)
			game->snakeHead->x -= 64.f * deltaTime;
		if (upPressed)
			game->snakeHead->y -= 64.f * deltaTime;
		if (downPressed)
			game->snakeHead->y += 64.f * deltaTime;

		player_pos_update(game->snakeHead);
		//fprintf(stderr, "%d", (int)control.rightPressed);
		//player_input(event, control);
		//player_pos_update(game->snakeHead, control);
		game_renderer(game->renderer);
		player_renderer(game->renderer, game->snakeHead);

		//SDL_RenderPresent(game->renderer);
	}

	//end of program
	destroy_game(game);

	return 0;
}
