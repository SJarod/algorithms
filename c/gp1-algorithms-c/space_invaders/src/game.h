#pragma once

#include <stdbool.h>

// Game constants
#define MAX_ENEMIES 64
#define MAX_BULLETS 512
const int   SCREEN_PADDING;      // px
const float PLAYER_SPEED;        // px/s
const float PLAYER_BULLET_SPEED; // px/s
const int   PLAYER_WIDTH;        // px
const int   PLAYER_HEIGHT;       // px
const int   ENEMY_WIDTH;         // px
const int   ENEMY_HEIGHT;        // px
const float ENEMY_START_SPEED;   // px/s
const float ENEMY_MAX_SPEED;     // px/s
const float ENEMY_BULLET_SPEED;  // px/s
const int   ENEMY_ROW_HEIGHT;    // px
const int   ENEMY_ROWS;          // units
const int   ENEMY_COLUMNS;       // units

typedef enum game_buttons_e
{
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_FIRE,

    BUTTON_DEBUG1,
    BUTTON_DEBUG2,
    BUTTON_DEBUG3,
    BUTTON_DEBUG4,

    BUTTON_COUNT
} game_buttons_e;

typedef struct game_inputs_t
{
    bool buttons[BUTTON_COUNT];
    float deltaTime;

} game_inputs_t;

typedef struct player_t
{
    float x;
    float y;
    bool canShoot; // Player can shoot only if BUTTON_FIRE has been released after the previous shot
} player_t;

typedef struct enemy_t
{
    float x;
    float y;
} enemy_t;

typedef struct bullet_t
{
    float x;
    float y;
} bullet_t;

typedef struct game_t
{
    // Size in pixels
    int width;
    int height;

    player_t player;

    bool playerBulletAlive;
    bullet_t playerBullet;

    float enemySpeed;   // Enemy speed increase progressively
    int enemyDirection; // -1: left, +1: right
    int enemyCount;
    enemy_t enemies[MAX_ENEMIES];

    int enemyBulletCount;
    bullet_t enemyBullets[MAX_BULLETS];

    float enemyShootTimer;
} game_t;

void game_init(game_t* game, int width, int height);
void game_destroy(game_t* game);

int game_update(game_t* game, const game_inputs_t* inputs);

