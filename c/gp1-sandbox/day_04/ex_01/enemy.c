#include "enemy.h"
#include "my_put_string.h"
#include "string_length.h"

#include <stdlib.h>

void enemy_construct(struct s_enemy* enemy, int l, int a, char* n, char* c)
{
	if (enemy == 0)
		return;
	if (n == 0)
	{
		enemy->name = 0;
		enemy->cry = 0;
		return;
	}
	if (c == 0)
	{
		enemy->name = 0;
		enemy->name = 0;
		return;
	}

	enemy->name = malloc(string_length(n) * sizeof(char));
	enemy->cry = malloc(string_length(c) * sizeof(char));

	enemy->life = l;
	enemy->attack = a;

	for (unsigned int i = 0; i < string_length(n); ++i)
	{
		enemy->name[i] = n[i];
	}

	for (unsigned int i = 0; i < string_length(c); ++i)
	{
		enemy->cry[i] = c[i];
	}
	
	my_put_string(enemy->name);
	my_put_string(" is born.\n");
}

void enemy_cry(const t_enemy* enemy)
{
	if (enemy == 0)
		return;
	if (enemy->name == 0 || enemy->cry == 0)
		return;

	my_put_string(enemy->name);
	my_put_string(": ");
	my_put_string(enemy->cry);
	my_put_string("\n");
}

void enemy_destruct(struct s_enemy* enemy)
{
	if (enemy == 0)
		return;
	if (enemy->name == 0 || enemy->cry == 0)
	{
		free(enemy->name);
		free(enemy->cry);
		return;
	}

	my_put_string(enemy->name);
	my_put_string(" died.");
	my_put_string("\n");

	free(enemy->name);
	free(enemy->cry);
}
