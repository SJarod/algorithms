
#include <stdlib.h>
#include "game.h"

float get_enemy_speed(int remaining)
{
    int max_enemies = ENEMY_ROWS * ENEMY_COLUMNS;
    return ENEMY_START_SPEED + ((max_enemies - remaining) / (float)max_enemies) * (ENEMY_MAX_SPEED - ENEMY_START_SPEED);
}

float get_enemy_shoot_speed(int remaining)
{
    return 1.f; 
}

float clamp(float x, float minValue, float maxValue)
{
    if (x < minValue)
        return minValue;
    else if (x > maxValue)
        return maxValue;
    else
        return x;
}

bool point_inside_rect(float x, float y, float rx, float ry, float rw, float rh)
{
    return (x >= rx && x < rx + rw) &&
           (y >= ry && y < ry + rh);
}

// Move player using inputs (LEFT,RIGHT) and PLAYER_SPEED
// Player should stay inside the screen (use SCREEN_PADDING)
void move_player(game_t* game, const game_inputs_t* inputs)
{
    if (inputs->buttons[BUTTON_LEFT])
        game->player.x -= inputs->deltaTime * PLAYER_SPEED;
    if (inputs->buttons[BUTTON_RIGHT])
        game->player.x += inputs->deltaTime * PLAYER_SPEED;
    
    game->player.x = clamp(game->player.x, 10, 100);
}

// playerBullet is set to the player position and set alive
void player_shoot(game_t* game)
{

}

// Each enemies are moved using enemyDirection and enemySpeed
// If an enemy reach the border of the screen, the direction is changed the next frame
void move_enemies(game_t* game, float deltaTime)
{

}

// A random enemy is selected to fire a bullet
// A new bullet is added to the list of bullets
void random_enemy_fire(game_t* game)
{

}

// Move the single player bullet
// Set playerBulletAlive to false if bullet is out of bound
void move_player_bullet(game_t* game, float deltaTime)
{

}

// Remove enemy from enemies
void remove_enemy(game_t* game, int enemyIndex)
{

}

// Remove enemy bullet from enemyBullets
void remove_enemy_bullet(game_t* game, int enemyBulletIndex)
{

}

// Move every enemy bullets
// Remove the bullet if out of range
void move_enemies_bullets(game_t* game, float deltaTime)
{

}

// Check if the player is hit by a bullet using bullet position and PLAYER_WIDTH/PLAYER_HEIGHT
bool player_is_hit_by_bullet(player_t* player, bullet_t* bullet)
{
    return false;
}

// Check if the enemy is hit by a bullet using bullet position and ENEMY_WIDTH/ENEMY_HEIGHT
bool enemy_is_hit_by_bullet(enemy_t* enemy, bullet_t* bullet)
{
    return false;
}
