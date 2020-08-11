#ifndef __ENEMY__
#define __ENEMY__

typedef struct s_enemy
{
	char* name;
	int life;
	int attack;
	char* cry;

} t_enemy;

void enemy_construct(struct s_enemy* enemy, int life, int attack, char* name, char* cry);
void enemy_cry(const t_enemy* enemy);
void enemy_destruct(struct s_enemy* enemy);

#endif
