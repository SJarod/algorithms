#include <stdlib.h>

#include "enemy.h"
#include "player.h"
#include "weapon.h"
#include "my_put_number.h"
#include "my_put_string.h"

int main(int ac, char ** av)
{
	struct s_player myself;

	player_construct(&myself, 100, 1, "Me", "THIS IS SPARTAAAAAA!!!");

	my_put_string("Player:\n");
	my_put_string(" - name: ");
	my_put_string(myself.name);
	my_put_string("\n - life: ");
	my_put_number(myself.life);
	my_put_string("\n - armor: ");
	my_put_number(myself.armor);
	my_put_string("\n - shout: ");
	my_put_string(myself.shout);
	my_put_string("\n\n");
	const t_player* saved_self = &myself;
	player_shout(saved_self);

	t_enemy nemesis;
	const t_enemy* invincible_nemesis = &nemesis;
	enemy_construct(&nemesis, 200, 10, "Nemesis", "I will find you and kill you");
	enemy_attack(invincible_nemesis, &myself);
	my_put_string("Player life after enemy attack: ");
	my_put_number(saved_self->life);
	my_put_char('\n');

	player_attack(saved_self, &nemesis);
	t_weapon* sword = create_weapon("two-handed sword", 25);
	player_pickup_weapon(&myself, sword);
	player_attack(saved_self, &nemesis);

	my_put_string("Enemy life after player attack: ");
	my_put_number(invincible_nemesis->life);
	my_put_char('\n');

	enemy_destruct(&nemesis);
	player_destruct(&myself);

	return EXIT_SUCCESS;
}
