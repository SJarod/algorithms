#include "enemy.h"
#include "player.h"
#include "my_put_string.h"
#include "weapon.h"
#include "string_length.h"

#include <stdlib.h>

void player_construct(struct s_player* player,
		      int life,
		      int armor,
		      char* name,
		      char* shout)
{
	if (player == NULL)
		return;
	if (name == NULL)
		return;
	if (shout == NULL)
		return;

	player->name = malloc((string_length(name) + 1) * sizeof(char));
	player->shout = malloc((string_length(shout) + 1) * sizeof(char));

	for (unsigned int i = 0; i <= string_length(name); ++i)
	{
		player->name[i] = name[i];
	}

	for (unsigned int i = 0; i <= string_length(shout); ++i)
	{
		player->shout[i] = shout[i];
	}

	player->life = life;
	player->armor = armor;
	player->haveWeapon = 0;
	player->damage = 0;
	player->weapon = NULL;

	my_put_string(player->name);
	my_put_string(": ");
	my_put_string("I'm alive!\n");
}

void player_shout(const t_player* player)
{
	if (player == NULL)
		return;

	my_put_string(player->shout);
	my_put_string("\n");
}

void player_attack(const t_player* player, struct s_enemy* enemy)
{
	if (player == NULL)
		return;
	if (enemy == NULL)
		return;

	if (player->haveWeapon == 0)
	{
		my_put_string(player->name);
		my_put_string(": ");
		my_put_string("I can't attack without a weapon!\n");
	}
	else
	{
		my_put_string(player->name);
		my_put_string(": You'll die first!\n");
		enemy->life -= player->damage;
	}
}

void player_pickup_weapon(struct s_player* player, t_weapon* weapon)
{
	if (player == NULL)
		return;
	if (weapon == NULL)
		return;

	player->weapon = weapon;

	my_put_string(player->name);
	my_put_string(": Yeah! I found a ");
	my_put_string(weapon->name);
	my_put_string("!\n");

	player->haveWeapon = 1;
	player->damage = weapon->damage;
}

void player_destruct(struct s_player* player)
{
	if (player == NULL)
		return;

	my_put_string(player->name);
	my_put_string(" put his ");
	my_put_string(player->weapon->name);
	my_put_string(" away and retired after doing great deeds.");
	my_put_string("\n");

	free(player->weapon->name);
	free(player->weapon);
	free(player->name);
	free(player->shout);
}
