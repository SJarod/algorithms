#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/player.h"
#include "../include/game.h"

t_player* create_player()
{
	t_player* player = malloc(sizeof(t_player));
	player->x = 352.f;
	player->y = 224.f;

	player->next = NULL;
	player->isTail = true;
	player->speed = 100;

	player->next = create_body(player);
	player->next->next = create_body(player->next);
	player->next->next->next = create_body(player->next->next);
	//player->next->next->next->next = create_body(player->next->next->next);

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
}

void player_pos_update(t_player* player)
{
	int count = 0;
	float tempx = 0;
	float tempy = 0;
	t_player* temp = player;

	while (temp->isTail == false)
	{
		temp = temp->next;
		++count;
	}

	SDL_Delay(player->speed);

	for (int i = count; i > 0; --i)
	{
		temp = player;

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
	temp = player;
	int count = 0;

	while (temp->isTail == false)
	{
		temp = temp->next;
		++count;
	}

	for (int i = 0; i < count; ++i)
	{
		temp = player;

		while (temp->next->isTail == false)
		{
			temp = temp->next;
		}

		free(temp->next);
		temp->isTail = true;
		temp->next = NULL;
	}
}
