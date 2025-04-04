#ifndef __CRATE__
#define __CRATE__

typedef struct s_position t_position;

typedef struct s_crate
{
	char const* name;
	t_position* pos;
	int is_alive;

} t_crate;

void	crate_explosion_event(void* p_entity, char const* explosion_name, t_position const* p_position);
void	spawn_crate(char const* name, float x, float y);

#endif
