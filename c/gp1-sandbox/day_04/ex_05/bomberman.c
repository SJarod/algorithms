#include "world.h"
#include "bomberman.h"
//#include "world.h"
#include "crate.h"
#include "barrel.h"

#include "my_put_string.h"

#include <stdlib.h>

void bomberman_explosion_event(void* p_entity, char const* explosion_name, t_position const* p_position)
{
	if (p_entity == NULL)
		return;
	if (explosion_name == NULL)
		return;
	if (p_position == NULL)
		return;

	t_bomberman* bomberman = p_entity;

	if (bomberman->life <= 0)
		return;

	/*if (bomberman->pos.x < p_position->x + p_position->radius &&
	    bomberman->pos.x > p_position->x - p_position->radius &&
	    bomberman->pos.y < p_position->y + p_position->radius &&
	    bomberman->pos.y > p_position->y - p_position->radius)*/
	if (collision_happens(bomberman->pos, p_position) == 1)
	{
		bomberman->life -= 10;
		my_put_string(bomberman->name);
		my_put_string(" is hit by explosion ");
		my_put_string(explosion_name);
		my_put_string("!\n");

		if (bomberman->life <= 0)
		{
			my_put_string(bomberman->name);
			my_put_string(" is dead!\n");

			//free(bomberman->pos);
			//free(bomberman);
		}
	}

	//free(bomberman->pos);
	//free(bomberman);
}

void spawn_bomberman(char const* name, float x, float y)
{
	if (name == NULL)
		return;

	t_bomberman* bomberman;
	bomberman = malloc(sizeof(t_bomberman));
	bomberman->pos = malloc(sizeof(t_position));

	bomberman->name = name;
	bomberman->pos->x = x;
	bomberman->pos->y = y;
	bomberman->pos->radius = 1.0f;
	bomberman->life = 20;

	add_entity(bomberman, bomberman_explosion_event);

	//free(bomberman->pos);
	//free(bomberman);
}
