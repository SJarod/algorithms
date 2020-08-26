#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

t_food* create_food()
{
	t_food* food = malloc(sizeof(t_food));
	food->x = (((rand() % 22) + 1) * 32) + 64;
	food->y = (((rand() % 15) + 1) * 32) + 64;

	if (food->x > 704)
		food->x -= 64;
	if (food->y > 480)
		food->y -= 64;

	return food;
}

void food_renderer(SDL_Renderer* renderer, t_food* food)
{
	SDL_SetRenderDrawColor(renderer, 36, 41, 32, 255);

	SDL_Rect rect = {food->x, food->y, 32, 32};
	SDL_Rect src = {0, 0, 32, 32};

	SDL_Surface* surface = IMG_Load("../media/assets/apple.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_RenderCopy(renderer, texture, &src, &rect);

	SDL_RenderPresent(renderer);
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

	if (game->snakeHead->x == food->x &&
	    game->snakeHead->y == food->y)
	{
		t_player* tempSnake = game->snakeHead;

		while (tempSnake->isTail == false)
		{
			tempSnake = tempSnake->next;
		}

		game->score += 1;
		tempSnake->next = create_body(tempSnake);

		free(food);
		return 0;
	}

	return 1;
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
