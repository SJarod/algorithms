#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/player.h"
#include "../include/game.h"

t_player* create_player()
{
	t_player* player = malloc(sizeof(t_player));
	player->x = 368.f;
	player->y = 268.f;

	player->next = NULL;
	player->isTail = true;

	player->next = create_body(player);
	player->next->x -= 64;
	player->next->next = create_body(player->next);
	player->next->next->x -= 64;
	player->next->next->next = create_body(player->next->next);
	player->next->next->next->x -= 64;
player->next->next->next->next = create_body(player->next->next->next);
player->next->next->next->next->x -= 64;

	return player;
}

t_player* create_body(t_player* player)
{
	if (player == NULL)
		return NULL;

	if (player->isTail == true)
	{
		t_player* newBody = malloc(sizeof(t_player));
		player->next = newBody;	//assinging to next node
		newBody->x = player->x;
		newBody->y = player->y;

		newBody->next = NULL;
		newBody->isTail = true;	//new tail
		player->isTail = false;

		return newBody;
	}

	return NULL;
}

void player_renderer(SDL_Renderer* renderer, t_player* player)
{
	SDL_SetRenderDrawColor(renderer, 36, 41, 32, 255);
	t_player* temp = player;

	while (temp->next != NULL)
	{
		SDL_Rect rect = {temp->x, temp->y, 32, 32};
		temp = temp->next;

		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderPresent(renderer);
	}

	SDL_Rect rect = {temp->x, temp->y, 32, 32};

	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);
}

t_control player_input(SDL_Event event, t_control control)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			control.rightPressed = true;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
		{
			control.leftPressed = true;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_UP)
		{
			control.upPressed = true;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
		{
			control.downPressed = true;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			control.rightPressed = false;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
		{
			control.leftPressed = false;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_UP)
		{
			control.upPressed = false;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
		{
			control.downPressed = false;
		}
	}
}

void player_pos_update(t_player* player)
{
	int count = 0;
	t_player* temp = player;

	while (temp->isTail == false)
	{
		temp = temp->next;
		++count;
	}

	//SDL_Delay(450);

	for (int i = count; i > 0; --i)
	{
		temp = player;
		//SDL_Delay(200);

		for (int j = i - 1; j > 0; --j)
		{
			temp = temp->next;
		}

		temp->next->x = temp->x;
		temp->next->y = temp->y;
	}	
}

void destroy_player(t_player* player)
{
	if (player == NULL)
		return;

	t_player* temp;

	for (int i = 0; i < 3; ++i)
	{
		temp = player;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		fprintf(stderr, "node free");
		free(temp);
		temp = NULL;
	}
}
