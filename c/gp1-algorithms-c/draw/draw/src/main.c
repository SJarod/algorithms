
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <gp/gp.h>

#include "draw.h"

void draw_render(GPLib* gp, GPFont font, const draw_t* draw)
{
    const char* states[DS_COUNT] = 
    {
        "Nothing",
        "Noise",
        "Points",
        "Lines (naive)",
        "Lines (Bresenham)"
    };

    gpDrawText(gp, font, (GPVector2){16.f, 32.f}, (GPColor){1.f, 1.f, 0.f, 1.f}, "State %d: %s", draw->state, states[draw->state]);
}

void invertPixels(color_t* dst, color_t* src, int width, int height)
{
    for (int y = 0; y < height; ++y)
        memcpy(&dst[y * width], &src[(height-y-1) * width], width * sizeof(color_t));
}

int main(int argc, char* argv[])
{
    const int   WIDTH  = 60;
    const int   HEIGHT = 40;
    const int   SCALE  = 16;
    const char* TITLE  = "Draw!";

    // Init system
    GPLib* gp = gpInit(WIDTH * SCALE, HEIGHT * SCALE, TITLE, GP_VSYNC_ON);
    if (gp == NULL)
    {
        fprintf(stderr, "Cannot init gplib\n");
        return 1;
    }

    // Create intermediate framebuffer with lower resolution
    GPFramebuffer screen = gpFramebufferLoad(gp, WIDTH, HEIGHT);
    color_t* pixels = calloc(WIDTH * HEIGHT, sizeof(color_t));
    color_t* invertedPixels = calloc(WIDTH * HEIGHT, sizeof(color_t));

    // Init font
    GPFont font = gpFontLoad(gp, "media/Renogare-Regular.otf", 32);

    // Init 'draw' system
    inputs_t inputs   = { .width  = WIDTH, .height = HEIGHT };
    outputs_t outputs = { .pixels = pixels };
    draw_t draw;
    draw_init(&draw, &inputs);

    // Main loop
    while (!gpWindowShouldClose(gp))
    {
        gpEventsPoll(gp);

        // Update game
        inputs.nextState = gpKeyIsPressed(gp, GP_KEY_RIGHT);
        inputs.prevState = gpKeyIsPressed(gp, GP_KEY_LEFT);
        inputs.phaseUp = gpKeyIsDown(gp, GP_KEY_UP);
        inputs.phaseDown = gpKeyIsDown(gp, GP_KEY_DOWN);
        inputs.deltaTime = gpGetFrameTime(gp);
        inputs.time = gpGetTime(gp);

        draw_update(&draw, &inputs, &outputs);

        // Render game
        gpDrawBegin(gp);
        gpFramebufferDrawBegin(gp, screen);
        gpDrawClearBackground(gp, (GPColor){0.2f, 0.2f, 0.2f, 1.f});

        // Draw here!
        invertPixels(invertedPixels, pixels, inputs.width, inputs.height);

        gpTextureUpdate(gp, screen.texture, (GPColor*)invertedPixels);
        
        gpFramebufferDrawEnd(gp);

        gpDrawTextureEx2(gp, screen.texture, (GPRect){0.f, 0.f, WIDTH, HEIGHT}, (GPRect){ 0.f, 0.f, WIDTH*SCALE, HEIGHT*SCALE }, GP_CWHITE);

        draw_render(gp, font, &draw);
        gpDrawEnd(gp);
    }

    free(pixels);
    free(invertedPixels);

    // Shutdown system
    gpFontUnload(gp, font);
    gpShutdown(gp);
    return 0;
}

