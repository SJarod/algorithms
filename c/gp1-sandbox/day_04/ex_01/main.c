#include <stdlib.h>

#include "enemy.h"
#include "my_put_number.h"
#include "my_put_string.h"

int main(int ac, char ** av)
{
	(void)ac;
	(void)av;

	struct s_enemy	my_enemy;

	enemy_construct(&my_enemy, 30, 9, "NastyGuy", "Let's get nasty!");

	my_put_string("Enemy:\n");
	my_put_string(" - name: ");
	my_put_string(my_enemy.name);
	my_put_string("\n - life: ");
	my_put_number(my_enemy.life);
	my_put_string("\n - attack: ");
	my_put_number(my_enemy.attack);
	my_put_string("\n - cry: ");
	my_put_string(my_enemy.cry);
	my_put_string("\n\n");
	enemy_cry(&my_enemy);
	enemy_destruct(&my_enemy);

	t_enemy*	modifiable_enemy = &my_enemy;
	const t_enemy*	the_boss = modifiable_enemy;

	enemy_construct(modifiable_enemy, 1, 1, "UglyThing", "Gwaaaaaaaaaaarggl!!!");
	enemy_cry(the_boss);
	enemy_destruct(modifiable_enemy);

	return EXIT_SUCCESS;
}
