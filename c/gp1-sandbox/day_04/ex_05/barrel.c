#include "world.h"
#include "barrel.h"
//#include "world.h"
#include "crate.h"
#include "bomberman.h"

#include "my_put_string.h"

#include <stdlib.h>

void barrel_explosion_event(void* p_entity, char const* explosion_name, t_position const* p_position)
{
	if (p_entity == NULL)
		return;
	if (explosion_name == NULL)
		return;
	if (p_position == NULL)
		return;

	t_barrel* barrel = p_entity;

	if (barrel->is_exploded == 1)
		return;

	/*if (barrel->pos.x < p_position->x + p_position->radius &&
	    barrel->pos.x > p_position->x - p_position->radius &&
	    barrel->pos.y < p_position->y + p_position->radius &&
	    barrel->pos.y > p_position->y - p_position->radius)*/
	if (collision_happens(barrel->pos, p_position) == 1)
	{
		my_put_string("Barrel ");
		my_put_string(barrel->name);
		my_put_string(" exploded because of explosion ");
		my_put_string(explosion_name);
		my_put_string("!\n");

		barrel->is_exploded = 1;
		barrel->pos->radius = 10;

		send_explosion_event(barrel, barrel->name, barrel->pos);

		free(barrel->pos);
		free(barrel);
	}

	//free(barrel->pos);
	//free(barrel);
}

void spawn_barrel(char const* name, float x, float y)
{
	if (name == NULL)
		return;

	t_barrel* barrel;
	barrel = malloc(sizeof(t_barrel));
	barrel->pos = malloc(sizeof(t_position));

	barrel->name = name;
	barrel->pos->x = x;
	barrel->pos->y = y;
	barrel->pos->radius = 0.2f;

	add_entity(barrel, barrel_explosion_event);

	//free(barrel->pos);
	//free(barrel);
}
