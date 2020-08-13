#ifndef __BARREL__
#define __BARREL__

typedef struct s_position t_position;

typedef struct s_barrel
{
	char const* name;
	t_position* pos;
	int is_exploded;

} t_barrel;

void	barrel_explosion_event(void* p_entity, char const* explosion_name, t_position const* p_position);
void	spawn_barrel(char const* name, float x, float y);

#endif
