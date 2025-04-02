#include "weapon.h"
#include "my_put_string.h"
#include "string_length.h"

#include <stdlib.h>

t_weapon* create_weapon(char* name, int damage)
{
	if (name == NULL)
		return NULL;
	
	t_weapon* weapon_ptr = malloc(sizeof(t_weapon));	//not to return NULL
	weapon_ptr->name = malloc((string_length(name) + 1) * sizeof(char));

	for (unsigned int i = 0; i <= string_length(name); ++i)
	{
		weapon_ptr->name[i] = name[i];
	}

	weapon_ptr->damage = damage;

	my_put_string(weapon_ptr->name);
	my_put_string(" spawned.\n");

	return weapon_ptr;
}

void weapon_destruct(t_weapon* weapon)
{
	if (weapon == NULL)
		return;

	free(weapon->name);
}
