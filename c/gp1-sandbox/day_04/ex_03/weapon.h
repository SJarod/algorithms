#ifndef __WEAPON__
#define __WEAPON__

typedef struct s_weapon
{
	char* name;
	int damage;

} t_weapon;

t_weapon* create_weapon(char* name, int damage);
void weapon_destruct(t_weapon* weapon);

#endif
