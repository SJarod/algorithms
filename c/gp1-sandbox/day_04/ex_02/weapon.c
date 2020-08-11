#include "weapon.h"
#include "my_put_string.h"
#include "string_length.h"

#include <stdlib.h>

t_weapon* create_weapon(char* name, int damage)
{
	if (name == NULL)
		return NULL;
	
	t_weapon weapon;
	weapon->name = malloc((string_length(name) + 1) * sizeof(char));

	for (int i = 0; i <= string_length(name); ++i)
	{
		weapon->name[i] = name[i];
	}

	weapon->damage = damage;

	my_put_string(weapon->name);
	my_put_string(" spawned\n");

	return weapon;
}

void weapon_destruct(t_weapon* weapon)
{
	if (weapon == NULL)
		return;

	free(weapon->name);
}
