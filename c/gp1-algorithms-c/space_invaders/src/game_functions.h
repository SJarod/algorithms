#pragma once

#include <stdbool.h>

typedef struct game_t game_t;

float get_enemy_speed(int remaining);
float get_enemy_shoot_speed(int remaining);

// Move player using inputs (LEFT,RIGHT) and PLAYER_SPEED
// Player should stay inside the screen
void move_player(game_t* game, const game_inputs_t* inputs);

// playerBullet is set to the player position and set alive
void player_shoot(game_t* game);

// Each enemies are moved using enemyDirection and enemySpeed
// If an enemy reach the border of the screen, the direction is changed the next frame
void move_enemies(game_t* game, float deltaTime);

// A random enemy is selected to fire a bullet
// A new bullet is added to the list of bullets
void random_enemy_fire(game_t* game);

// Move the single player bullet
// Set playerBulletAlive to false if bullet is out of bound
void move_player_bullet(game_t* game, float deltaTime);

// Remove enemy from enemies
void remove_enemy(game_t* game, int enemyIndex);

// Remove enemy bullet from enemyBullets
void remove_enemy_bullet(game_t* game, int enemyBulletIndex);

// Move every enemy bullets
// Remove the bullet if out of range
void move_enemies_bullets(game_t* game, float deltaTime);

// Check if the player is hit by a bullet using bullet position and PLAYER_WIDTH/PLAYER_HEIGHT
bool player_is_hit_by_bullet(player_t* player, bullet_t* bullet);

// Check if the enemy is hit by a bullet using bullet position and ENEMY_WIDTH/ENEMY_HEIGHT
bool enemy_is_hit_by_bullet(enemy_t* enemy, bullet_t* bullet);
