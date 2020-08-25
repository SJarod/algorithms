#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "../include/player.h"

//player struct
typedef struct s_player t_player;

//struct to store info about the window
typedef struct s_game
{
	SDL_Window*	window;
	SDL_Renderer*	renderer;
	bool		isProgramRunning;
	t_player*	snakeHead;

} t_game;

//struct to store info about every tiles of the board
typedef struct s_board
{
	int			x;
	int			y;
	struct s_board*		up;	//pointer to tile above
	struct s_board*		down;	//pointer to tile below
	struct s_board*		right;	//pointer to right tile
	struct s_board*		left;	//pointer to left tile
	//pointers are NULL if tile is on edge

} t_board;

typedef struct s_control
{
	bool	upPressed;
	bool	downPressed;
	bool	rightPressed;
	bool	leftPressed;

} t_control;

//create the window and the game
t_game*	create_game();

//render and display
void	game_renderer(SDL_Renderer* renderer);

//destroy the game and then the window
void	destroy_game(t_game* game);

#endif
