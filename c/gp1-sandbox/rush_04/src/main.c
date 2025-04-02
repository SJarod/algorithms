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

	//program running
	game_loop(game);

	//end of program
	destroy_game(game);
	SDL_Quit;

	return 0;
}
