#ifndef __WORLD__
#define __WORLD__

typedef struct s_position 
{
	float x;
	float y;
	float radius;

} t_position;

typedef void (*t_explosion_event_callback)(void* entity, char const* explosion_name, t_position const* position);	//function pointer

typedef struct s_entity_info
{
	void* entity;
	t_explosion_event_callback explosion_callback;

} t_entity_info;

typedef struct s_world
{
	t_entity_info entities[100];
	unsigned int nbr_entities;

} t_world;

int	collision_happens(t_position const* p_position1, t_position const* p_position2);
void	initialize_world();
void	add_entity(void* p_entity, t_explosion_event_callback explosion_callback);	//takes a t_explosion_event_callback type as parameters
void	delete_world();
void	send_explosion_event(void* explosion_sender, char const* explosion_name, t_position const* explosion_position);

#endif
