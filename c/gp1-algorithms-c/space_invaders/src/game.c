
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

#include "game_functions.h"

const int   ENEMY_WIDTH         = 10;    // px
const int   ENEMY_HEIGHT        = 6;     // px
const int   PLAYER_WIDTH        = 4;     // px
const int   PLAYER_HEIGHT       = 3;     // px

// INTERNAL VALUES
const int   SCREEN_PADDING      = 10;    // px
const float PLAYER_SPEED        = 120.f; // px/s
const float PLAYER_BULLET_SPEED = 220.f; // px/s
const float ENEMY_START_SPEED   = 2.f;   // px/s
const float ENEMY_MAX_SPEED     = 40.f;  // px/s
const float ENEMY_BULLET_SPEED  = 110.f; // px/s
const int   ENEMY_ROW_HEIGHT    = 12;    // px
const int   ENEMY_ROWS          = 5;     // units
const int   ENEMY_COLUMNS       = 11;    // units

void game_init(game_t* game, int width, int height)
{
    *game = (game_t){ .width = width, .height = height };

    // Init player
    game->player.x = width / 2.f;
    game->player.y = height - 10;
    game->player.canShoot = true;

    // Init enemies
    {
        game->enemySpeed = ENEMY_START_SPEED;
        game->enemyDirection = 1;

        int rows = ENEMY_ROWS;
        int columns = ENEMY_COLUMNS;
        game->enemyCount = rows * columns;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < columns; ++c)
            {
                enemy_t* enemy = &game->enemies[c + r * columns];
                enemy->x = SCREEN_PADDING + (width - 3 * SCREEN_PADDING) * c / columns;
                enemy->y = SCREEN_PADDING + r * ENEMY_ROW_HEIGHT;
            }
        }
        game->enemyShootTimer = get_enemy_shoot_speed(game->enemyCount);
    }
}

void game_destroy(game_t* game)
{
    // Nothing to do
}

int game_update(game_t* game, const game_inputs_t* inputs)
{
    // Player update
    move_player(game, inputs);

    if (inputs->buttons[BUTTON_FIRE] && game->player.canShoot)
    {
        player_shoot(game);
        game->player.canShoot = false;
    }
    else if (inputs->buttons[BUTTON_FIRE] == false)
    {
        game->player.canShoot = true;
    }

    // Move enemies (and switch enemyDirection if needed)
    move_enemies(game, inputs->deltaTime);

    // Random enemy fire a bullet
    game->enemyShootTimer -= inputs->deltaTime;
    if (game->enemyShootTimer < 0.f)
    {
        random_enemy_fire(game);
        game->enemyShootTimer += get_enemy_shoot_speed(game->enemyCount);
    }

    // Move player bullet (if alive)
    move_player_bullet(game, inputs->deltaTime);

    // Move enemy bullets
    move_enemies_bullets(game, inputs->deltaTime);
    
    // Check enemy bullets collision with player
    for (int i = 0; i < game->enemyBulletCount; ++i)
    {
        bullet_t* bullet = &game->enemyBullets[i];
        if (player_is_hit_by_bullet(&game->player, bullet))
        {
            // TODO: Do proper death
            game->player.x = game->width / 2.f;
            game->enemyBulletCount = 0;
            game->enemyShootTimer = get_enemy_shoot_speed(game->enemyCount);
            break;
        }
    }

    // Check bullet collision with enemies
    if (game->playerBulletAlive)
    {
        for (int i = 0; i < game->enemyCount; ++i)
        {
            enemy_t* enemy = &game->enemies[i];
            if (enemy_is_hit_by_bullet(enemy, &game->playerBullet))
            {
                // Remove enemy
                remove_enemy(game, i);
                if (game->enemyCount > 0)
                    i -= 1;

                // Disable player bullet
                game->playerBulletAlive = false;
                game->enemySpeed = get_enemy_speed(game->enemyCount);
            }
        }
    }
}

