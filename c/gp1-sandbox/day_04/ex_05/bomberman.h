#ifndef __BOMBERMAN__
#define __BOMBERMAN__

typedef struct s_position t_position;

typedef struct s_bomberman
{
	char const* name;
	t_position pos;
	int life;

} t_bomberman;

void	bomberman_explosion_event(void* p_entity, char const* explosion_name, t_position const* p_position);
void	spawn_bomberman(char const* name, float x, float y);

#endif
