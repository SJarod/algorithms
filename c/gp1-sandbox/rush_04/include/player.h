#ifndef __PLAYER__
#define __PLAYER__

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "../include/game.h"

//game struct
typedef struct s_game t_game;

//struct to store info about the player
typedef struct s_player
{
	float			x;	//pos
	float			y;
	struct s_player*	next;
	bool			isTail;
	int			speed;

} t_player;

//create the player (only called once: creating head, 1 body and 1 tail)
t_player*	create_player();

//create a new body when snake eats an apple
t_player*	create_body(t_player* player);

//render and display the player
void		player_renderer(SDL_Renderer* renderer, t_player* player);

//player inputs handling
void		player_pos_update(t_player* player);

void		destroy_player(t_player* player);

#endif
