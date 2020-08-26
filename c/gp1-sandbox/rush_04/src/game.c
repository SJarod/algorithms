#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../include/int_to_alpha.h"
#include "../include/game.h"
#include "../include/player.h"

t_game* create_game()
{
	t_game* game = malloc(sizeof(t_game));

	if (SDL_CreateWindowAndRenderer(800, 600, 0, &game->window, &game->renderer) == -1)
	{
		SDL_Log("unable to create window: %s\n", SDL_GetError());
		return NULL;
	}

	//access to program loop
	game->isProgramRunning = true;
	game->isGameRunning = false;
	game->score = 0;

	game->snakeHead = create_player();

	return game;
}

void game_loop(t_game* game)
{
	game_renderer(game->renderer);
	bool	upPressed = false;
	bool	downPressed = false;
	bool	rightPressed = false;
	bool	leftPressed = false;
	int	oppositeV = 1;
	int	oppositeH = 1;
	int	apple = 0;
	int	activateCollision = 0;

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

			//update
			if (rightPressed)
				game->snakeHead->x += 32.f;
			if (leftPressed)
				game->snakeHead->x -= 32.f;
			if (upPressed)
				game->snakeHead->y -= 32.f;
			if (downPressed)
				game->snakeHead->y += 32.f;

			player_pos_update(game->snakeHead);

			//rendering screen and display
			game_renderer(game->renderer);
			score_renderer(game->renderer, game);
			player_renderer(game->renderer, game->snakeHead);

			if (activateCollision)
				is_collision(game);

			//snake movement
			if (rightPressed == true || leftPressed == true ||
			    upPressed == true	 || downPressed == true)
				activateCollision = 1;

			//apple spawn
			t_food* appleToEat;
			t_food* speedPlus;
			t_food* speedMinus;

			if (apple == 0)
			{
				appleToEat = create_food(APPLE, 1, &eat_apple);
				apple = is_food_collision(game, appleToEat);

				speedPlus = create_food(SPEEDP, rand() % 2, &eat_speedp);
				is_food_collision(game, speedPlus);	

				speedMinus = create_food(SPEEDM, rand() % 2, &eat_speedm);
				is_food_collision(game, speedMinus);
			}

			food_renderer(game->renderer, appleToEat);
			food_renderer(game->renderer, speedPlus);
			food_renderer(game->renderer, speedMinus);
			apple = is_food_collision(game, appleToEat);
			is_food_collision(game, speedPlus);
			is_food_collision(game, speedMinus);

			SDL_RenderPresent(game->renderer);
		}

		//while game has not started or is finished
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
}

void game_renderer(SDL_Renderer* renderer)
{
	if (renderer == NULL)
		return;

	//background of the renderer
	SDL_SetRenderDrawColor(renderer, 107, 130, 112, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 36, 41, 32, 255);
	SDL_Rect rect = {50, 50, 700, 500};
	SDL_RenderDrawRect(renderer, &rect);
}

t_food* create_food(foodType type, int spawn, void (*food_type)(t_game* game, struct s_food* food))
{
	if (spawn == 0)
		return NULL;

	t_food* food = malloc(sizeof(t_food));
	food->x = (((rand() % 22) + 1) * 32) + 64;
	food->y = (((rand() % 15) + 1) * 32) + 64;

	if (food->x > 704)
		food->x -= 64;
	if (food->y > 480)
		food->y -= 64;

	food->type = type;
	food->food_type = food_type;

	return food;
}

void food_renderer(SDL_Renderer* renderer, t_food* food)
{
	if (food == NULL)
		return;

	SDL_SetRenderDrawColor(renderer, 36, 41, 32, 255);

	SDL_Rect rect = {food->x, food->y, 32, 32};
	SDL_Rect src = {0, 0, 32, 32};

	SDL_Surface* surface;

	switch (food->type)
	{
		case APPLE:
			{
				surface = IMG_Load("../media/assets/apple.png");
				break;
			}
		case SPEEDP:
			{
				surface = IMG_Load("../media/assets/speedplus.png");
				break;
			}
		case SPEEDM:
			{
				surface = IMG_Load("../media/assets/speedminus.png");
				break;
			}
		default:
			{
				surface = IMG_Load("../media/assets/apple.png");
				break;
			}
	}
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_RenderCopy(renderer, texture, &src, &rect);
	SDL_DestroyTexture(texture);
}

void score_renderer(SDL_Renderer* renderer, t_game* game)
{
	//initializing fonts
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("../media/fonts/retro-gaming/Retro Gaming.ttf", 100);
	SDL_Color color = {36, 41, 32, 255};
	const char*	text = int_to_alpha(game->score);
	SDL_Surface* surfaceT = TTF_RenderText_Blended(font, text, color);
	SDL_Texture* textureT = SDL_CreateTextureFromSurface(renderer, surfaceT);
	SDL_FreeSurface(surfaceT);
	SDL_Rect textRect = {680, 10, 40, 35};

	SDL_RenderCopy(renderer, textureT, NULL, &textRect);

	//score title
	SDL_SetRenderDrawColor(renderer, 36, 41, 32, 255);

	SDL_Rect rect = {450, 10, 200, 30};
	SDL_Rect src = {0, 0, 375, 49};

	SDL_Surface* surface = IMG_Load("../media/assets/score.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_RenderCopy(renderer, texture, &src, &rect);
	TTF_CloseFont(font);
	SDL_DestroyTexture(textureT);
	SDL_DestroyTexture(texture);
}

void is_collision(t_game* game)
{
	if (game->snakeHead->x >= 720 ||
	    game->snakeHead->x <= 50  ||
	    game->snakeHead->y >= 520 ||
	    game->snakeHead->y <= 50)
	    game->isGameRunning = false;

	t_player* temp = game->snakeHead;
	int count = 0;

	while (temp->isTail == false)
	{
		++count;
		temp = temp->next;
	}

	temp = game->snakeHead->next->next;

	for (int i = count - 2; i > 0; --i)
	{
		if (game->snakeHead->x == temp->x &&
		    game->snakeHead->y == temp->y)
		    game->isGameRunning = false;

		temp = temp->next;
	}
}

int is_food_collision(t_game* game, t_food* food)
{
	if (game == NULL)
		return 1;
	if (food == NULL)
		return 0;

	if (game->snakeHead->x == food->x &&
	    game->snakeHead->y == food->y)
	{
		food->food_type(game, food);

		return 0;
	}

	return 1;
}

void eat_apple(t_game* game, t_food* food)
{
	t_player* tempSnake = game->snakeHead;

	while (tempSnake->isTail == false)
	{
		tempSnake = tempSnake->next;
	}

	game->score += 1;
	tempSnake->next = create_body(tempSnake);

	

	free(food);
}

void eat_speedp(t_game* game, t_food* food)
{
	game->snakeHead->speed -= 25;

	free(food);
}

void eat_speedm(t_game* game, t_food* food)
{
	game->snakeHead->speed += 25;

	free(food);
}

void destroy_game(t_game* game)
{
	if (game == NULL)
		return;

	destroy_player(game->snakeHead);
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	free(game);
}
