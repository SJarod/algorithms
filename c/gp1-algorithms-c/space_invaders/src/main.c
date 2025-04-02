
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <gp/gplib.h>

#include "game.h"

void bullet_render(GPLib* gp, const bullet_t* bullet)
{
    gpDrawRectFilled(gp, (GPRect){bullet->x, bullet->y, 1.f, 6.f}, GP_CBLACK);
}

void game_render(GPLib* gp, const game_t* game)
{
    // Render player
    {
        const player_t* player = &game->player;
        gpDrawCircleFilled(gp, (GPVector2){player->x, player->y}, 4.f, GP_CBLACK);
    }

    // Render enemies
    {
        for (int i = 0; i < game->enemyCount; ++i)
        {
            const enemy_t* enemy = &game->enemies[i];
            gpDrawRectFilled(gp, (GPRect){enemy->x - ENEMY_WIDTH / 2.f, enemy->y - ENEMY_HEIGHT / 2.f, ENEMY_WIDTH, ENEMY_HEIGHT}, GP_CBLACK);
        }
    }

    // Render bullets
    {
        if (game->playerBulletAlive)
            bullet_render(gp, &game->playerBullet);

        for (int i = 0; i < game->enemyBulletCount; ++i)
            bullet_render(gp, &game->enemyBullets[i]);

    }
}

int main(int argc, char* argv[])
{
    const int   WIDTH  = 240;
    const int   HEIGHT = 160;
    const int   SCALE  = 4;
    const char* TITLE  = "Invaders";

    // Init system
    GPLib* gp = gpInit(WIDTH * SCALE, HEIGHT * SCALE, TITLE, GP_VSYNC_ON);
    if (gp == NULL)
    {
        fprintf(stderr, "Cannot init gplib\n");
        return 1;
    }

    // Create intermediate framebuffer with lower resolution
    GPFramebuffer screen = gpFramebufferLoad(gp, WIDTH, HEIGHT);

    game_t game;
    game_init(&game, WIDTH, HEIGHT);

    int buttonMapping[BUTTON_COUNT] = {
        GP_KEY_LEFT,
        GP_KEY_RIGHT,
        GP_KEY_SPACE,
        GP_KEY_F1,
        GP_KEY_F2,
        GP_KEY_F3,
        GP_KEY_F4
    };

    // Main loop
    while (!gpWindowShouldClose(gp))
    {
        gpEventsPoll(gp);

        // Update game
        game_inputs_t inputs = {};
        for (int i = 0;i < BUTTON_COUNT; ++i)
        {
            inputs.buttons[i] = gpKeyIsDown(gp, buttonMapping[i]);
        }
        inputs.deltaTime = gpGetFrameTime(gp);

        game_update(&game, &inputs);

        // Render game
        gpDrawBegin(gp);
        gpFramebufferDrawBegin(gp, screen);
        gpDrawClearBackground(gp, (GPColor){0.8f, 0.8f, 0.8f, 1.f});

        // Draw here!
        game_render(gp, &game);
        
        gpFramebufferDrawEnd(gp);

        gpDrawTextureEx2(gp, screen.texture, (GPRect){0.f, 0.f, WIDTH, HEIGHT}, (GPRect){ 0.f, 0.f, WIDTH*SCALE, HEIGHT*SCALE }, GP_CWHITE);
        gpDrawEnd(gp);
    }

    game_destroy(&game);

    // Shutdown system
    gpShutdown(gp);
    return 0;
}

