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
	bool		isGameRunning;
	t_player*	snakeHead;
	int		score;

} t_game;

//type of food
typedef enum
{
	APPLE,
	SPEEDP,
	SPEEDM

} foodType;

//struct to store info about food (apple, bonus, ...)
typedef struct s_food
{
	int		x;
	int		y;
	foodType	type;
	void		(*food_type)(t_game* game, struct s_food* food);

} t_food;

//create the window and the game
t_game*	create_game();

//while the game is running
void	game_loop(t_game* game);

//render and display
void	game_renderer(SDL_Renderer* renderer);
t_food*	create_food(foodType type, int spawn, void (*food_type)(t_game* game, struct s_food* food));
void	food_renderer(SDL_Renderer* renderer, t_food* food);
void	score_renderer(SDL_Renderer* renderer, t_game* game);

//collision handling
void	is_collision(t_game* game);
int	is_food_collision(t_game* game, t_food* food);

void	eat_apple(t_game* game, t_food* food);
void	eat_speedp(t_game* game, t_food* food);
void	eat_speedm(t_game* game, t_food* food);

//destroy the game and then the window
void	destroy_game(t_game* game);

#endif
