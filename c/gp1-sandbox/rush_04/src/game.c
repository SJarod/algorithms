#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

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
}

void destroy_game(t_game* game)
{
	if (game == NULL)
		return;

	//destroy_player(game->snakeHead);
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	free(game);
	SDL_Quit;
}
