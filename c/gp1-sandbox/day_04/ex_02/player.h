#ifndef __PLAYER__
#define __PLAYER__

typedef struct s_weapon t_weapon;

typedef struct s_player
{
	char* name;
	int life;
	int armor;
	char* shout;
	int haveWeapon;
	int damage;
	t_weapon* weapon;

} t_player;

typedef struct s_enemy t_enemy;

void player_construct(struct s_player* player,
		      int life,
		      int armor,
		      char* name,
		      char* shout);
void player_shout(const t_player* player);
void player_attack(const t_player* player, t_enemy* enemy);
void player_pickup_weapon(struct s_player* player, t_weapon* weapon);
void player_destruct(struct s_player* player);

#endif
