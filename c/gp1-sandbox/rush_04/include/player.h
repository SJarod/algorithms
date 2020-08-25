#ifndef __PLAYER__
#define __PLAYER__

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "../include/game.h"

//game struct
typedef struct s_game t_game;
typedef struct s_control t_control;

//struct to store info about the player
typedef struct s_player
{
	float			x;	//pos
	float			y;
	struct s_player*	next;
	bool			isTail;

} t_player;

//create the player (only called once: creating head, 2 bodies and 1 tail)
t_player*	create_player();

//create a new body when snake eats an apple
t_player*	create_body(t_player* player);

//render and display the player
void		player_renderer(SDL_Renderer* renderer, t_player* player);

//player inputs handling
t_control	player_input(SDL_Event event, t_control control);
void		player_pos_update(t_player* player);

void		destroy_player(t_player* player);

#endif
