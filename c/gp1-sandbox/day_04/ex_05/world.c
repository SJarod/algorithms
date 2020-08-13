#include "world.h"
#include "crate.h"
#include "bomberman.h"
#include "barrel.h"

#include "my_put_string.h"

#include <stdlib.h>

t_world* the_world;
//the_world = malloc(sizeof(t_world));

int collision_happens(t_position const* p_position1, t_position const* p_position2)
{
	if (p_position1 == NULL)
		return 0;
	if (p_position2 == NULL)
		return 0;

	if (p_position1->x < p_position2->x + p_position2->radius &&
	    p_position1->x > p_position2->x - p_position2->radius &&
	    p_position1->y < p_position2->y + p_position2->radius &&
	    p_position1->y > p_position2->y - p_position2->radius)
		return 1;
	else
		return 0;
}

void initialize_world()
{
	//if (the_world == NULL)
	//	return;

	the_world = malloc(sizeof(t_world));
	the_world->nbr_entities = 0;
}

void add_entity(void* p_entity, t_explosion_event_callback explosion_callback)
{
	if (p_entity == NULL)
		return;

	if (the_world->nbr_entities >= 100)
		return;

	the_world->entities[the_world->nbr_entities].entity = p_entity;	//.entity is type void*
	the_world->entities[the_world->nbr_entities].explosion_callback = explosion_callback;	//.explosion_callback is the function pointer
	the_world->nbr_entities += 1;
}

void delete_world()
{
	/*for (unsigned int i = 0; i < the_world->nbr_entities; ++i)
	{
		//free(the_world->entities[i].entity->pos);
		free(&the_world->entities[i].entity);
	}*/

	//free(the_world->entities->entity);

	//free(the_world->entities->explosion_callback);
	free(the_world);
}

void send_explosion_event(void* explosion_sender, char const* explosion_name, t_position const* explosion_position)
{
	if (explosion_name == NULL)
		return;
	if (explosion_position == NULL)
		return;

	my_put_string("Explosion ");
	my_put_string(explosion_name);
	my_put_string(" happens!\n");

	if (explosion_sender == NULL)
	{
		for (unsigned int i = 0; i < the_world->nbr_entities; ++i)
		{
			the_world->entities[i].explosion_callback(the_world->entities[i].entity, explosion_name, explosion_position);
		}
	}
	else
	{
		for (unsigned int i = 0; i < the_world->nbr_entities; ++i)
		{
			the_world->entities[i].explosion_callback(the_world->entities[i].entity, explosion_name, explosion_position);
		}
	}
}
