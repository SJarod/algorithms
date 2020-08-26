#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../include/game.h"
#include "../include/player.h"

int main()
{
	//initialization of random number function
	srand(time(NULL));

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
	bool	upPressed = false;
	bool	downPressed = false;
	bool	rightPressed = false;
	bool	leftPressed = false;
	int	oppositeV = 1;
	int	oppositeH = 1;
	int	apple = 0;
	int	activateCollision = 0;

	Uint32 time = 0;

	while (game->isProgramRunning)
	{
		while (game->isGameRunning)
		{
			//input handling
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					rightPressed = false;
					leftPressed = false;
					upPressed = false;
					downPressed = false;
					game->isGameRunning = false;
				}
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						if (oppositeH == 1)
						{
							rightPressed = true;
							leftPressed = false;
							upPressed = false;
							downPressed = false;
							oppositeV = 1;
							oppositeH = 0;
						}
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						if (oppositeH == 1)
						{
							rightPressed = false;
							leftPressed = true;
							upPressed = false;
							downPressed = false;
							oppositeV = 1;
							oppositeH = 0;
						}
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_UP)
					{
						if (oppositeV == 1)
						{
							rightPressed = false;
							leftPressed = false;
							upPressed = true;
							downPressed = false;
							oppositeH = 1;
							oppositeV = 0;
						}
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
					{
						if (oppositeV == 1)
						{
							rightPressed = false;
							leftPressed = false;
							upPressed = false;
							downPressed = true;
							oppositeH = 1;
							oppositeV = 0;
						}
					}
				}
			}

			Uint32 currentTime = SDL_GetTicks();
			float deltaTime = ((float)currentTime - (float)time) / 1000.f;
			time = currentTime;

			//update
			if (rightPressed)
				game->snakeHead->x += 32.f;// * deltaTime;
			if (leftPressed)
				game->snakeHead->x -= 32.f;// * deltaTime;
			if (upPressed)
				game->snakeHead->y -= 32.f;// * deltaTime;
			if (downPressed)
				game->snakeHead->y += 32.f;// * deltaTime;

			player_pos_update(game->snakeHead);
			
			game_renderer(game->renderer);
			player_renderer(game->renderer, game->snakeHead);

			if (activateCollision)
				is_collision(game);

			//snake movement
			if (rightPressed == true || leftPressed == true ||
			    upPressed == true	 || downPressed == true)
				activateCollision = 1;

			//apple spawn
			t_food* appleToEat;

			if (apple == 0)
			{
				appleToEat = create_food();
				apple = is_food_collision(game, appleToEat);
			}

			food_renderer(game->renderer, appleToEat);
			apple = is_food_collision(game, appleToEat);
		}

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				game->isProgramRunning = false;
			}
			else if (event.type == SDL_KEYUP &&
				 event.key.keysym.scancode == SDL_SCANCODE_RETURN)
			{
				game->isGameRunning = true;
			}
		}
	}

	//end of program
	destroy_game(game);
	SDL_Quit;

	return 0;
}
