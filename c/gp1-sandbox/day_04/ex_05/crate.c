#include "world.h"
#include "crate.h"
//#include "world.h"
#include "bomberman.h"
#include "barrel.h"

#include "my_put_string.h"

#include <stdlib.h>

void crate_explosion_event(void* p_entity, char const* explosion_name, t_position const* p_position)
{
	if (p_entity == NULL)
		return;
	if (explosion_name == NULL)
		return;
	if (p_position == NULL)
		return;

	t_crate* crate = p_entity;

	if (crate->is_alive == 0)
		return;

	/*if (crate->position.x < p_position->x + p_position->radius &&
	    crate->position.x > p_position->x - p_position->radius &&
	    crate->position.y < p_position->y + p_position->radius &&
	    crate->position.y > p_position->y - p_position->radius)*/
	if (collision_happens(crate->pos, p_position) == 1)
	{
		crate->is_alive = 0;
		my_put_string(crate->name);
		my_put_string(" is destroyed by ");
		my_put_string(explosion_name);
		my_put_string("!\n");

		free(crate->pos);
		free(crate);
	}

	//free(crate->position);
	//free(crate);
}

void spawn_crate(char const* name, float x, float y)
{
	if (name == NULL)
		return;

	t_crate* crate;
	crate = malloc(sizeof(t_crate));
	crate->pos = malloc(sizeof(t_position));

	crate->name = name;
	crate->is_alive = 1;
	crate->pos->x = x;
	crate->pos->y = y;
	crate->pos->radius = 0.4f;
	
	add_entity(crate, crate_explosion_event);

	//free(crate->position);
	//free(crate);
}
