#include "player.h"
#include "enemy.h"
#include "my_put_string.h"
#include "string_length.h"

#include <stdlib.h>
#include <stddef.h>

void enemy_construct(struct s_enemy* enemy,
		     int life,
		     int attack,
		     char* name,
		     char* cry)
{
	if (enemy == NULL)
		return;
	if (name == NULL)
	{
		enemy->name = NULL;
		enemy->cry = NULL;
		return;
	}
	if (cry == NULL)
	{
		enemy->name = NULL;
		enemy->name = NULL;
		return;
	}

	enemy->name = malloc((string_length(name) + 1) * sizeof(char));
	enemy->cry = malloc((string_length(cry) + 1) * sizeof(char));

	enemy->life = life;
	enemy->attack = attack;

	for (unsigned int i = 0; i <= string_length(name); ++i)
	{
		enemy->name[i] = name[i];
	}

	for (unsigned int i = 0; i <= string_length(cry); ++i)
	{
		enemy->cry[i] = cry[i];
	}
	
	my_put_string(enemy->name);
	my_put_string(" is born.\n");
}

void enemy_cry(const t_enemy* enemy)
{
	if (enemy == NULL)
		return;
	if (enemy->name == NULL || enemy->cry == NULL)
	{
		return;
	}

	my_put_string(enemy->name);
	my_put_string(": ");
	my_put_string(enemy->cry);
	my_put_string("\n");
}

void enemy_attack(const t_enemy* enemy, struct s_player* player)
{
	if (enemy == NULL)
		return;
	if (player == NULL)
		return;

	my_put_string(enemy->name);
	my_put_string(": Mouhahaha! ");
	my_put_string(player->name);
	my_put_string(", you'll die by my hand!\n");
	player->life -= enemy->attack - player->armor;
}

void enemy_destruct(struct s_enemy* enemy)
{
	if (enemy == NULL)
		return;
	if (enemy->name == NULL || enemy->cry == NULL)
	{
		return;
	}

	my_put_string(enemy->name);
	my_put_string(" died.");
	my_put_string("\n");

	free(enemy->name);
	free(enemy->cry);
}
