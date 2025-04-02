
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
        "Lines (Bresenham)",
        "Koch branch",
        "Koch snowflake",
        "Koch branch on Archimedean spiral",
        "Fractal squares"
    };

    GPColor penColor = (GPColor){1.f, 1.f, 0.f, 1.f};
    float penY = 32.f;
    float offsetY = 32.f;

    gpDrawText(gp, font, (GPVector2){16.f, penY}, penColor, "State (left/right) = %d: %s", draw->state, states[draw->state]);
    penY += offsetY;
    gpDrawText(gp, font, (GPVector2){16.f, penY}, penColor, "Phase (down/up) = %.2f", draw->phase);
    penY += offsetY;
    gpDrawText(gp, font, (GPVector2){16.f, penY}, penColor, "Depth (F/D) = %d", draw->depth);
    penY += offsetY;
}

void invertPixels(color_t* dst, color_t* src, int width, int height)
{
    for (int y = 0; y < height; ++y)
        memcpy(&dst[y * width], &src[(height-y-1) * width], width * sizeof(color_t));
}

int main(int argc, char* argv[])
{
    int width  = 960;
    int height = 640;
    int scale  = 16;
    const char* TITLE  = "Draw!";

    // Init system
    GPLib* gp = gpInit(width, height, TITLE, GP_VSYNC_ON);
    if (gp == NULL)
    {
        fprintf(stderr, "Cannot init gplib\n");
        return 1;
    }

    int bufferWidth  = width / scale;
    int bufferHeight = height / scale;

    // Create intermediate framebuffer with lower resolution
    GPFramebuffer screen = gpFramebufferLoad(gp, bufferWidth, bufferHeight);
    color_t* pixels = calloc(bufferWidth * bufferHeight, sizeof(color_t));
    color_t* invertedPixels = calloc(bufferWidth * bufferHeight, sizeof(color_t));

    // Init font
    GPFont font = gpFontLoad(gp, "media/Renogare-Regular.otf", 32);

    // Init 'draw' system
    inputs_t inputs = {};
    outputs_t outputs = {};
    draw_t draw;
    draw_init(&draw, &inputs);

    // Main loop
    while (!gpWindowShouldClose(gp))
    {
        gpEventsPoll(gp);

        // Update game
        inputs.nextState = gpKeyIsPressed(gp, GP_KEY_RIGHT);
        inputs.prevState = gpKeyIsPressed(gp, GP_KEY_LEFT);
        inputs.phaseUp   = gpKeyIsDown(gp, GP_KEY_UP);
        inputs.phaseDown = gpKeyIsDown(gp, GP_KEY_DOWN);
        inputs.depthUp   = gpKeyIsPressed(gp, GP_KEY_F);
        inputs.depthDown = gpKeyIsPressed(gp, GP_KEY_D);
        inputs.deltaTime = gpGetFrameTime(gp);
        inputs.time = gpGetTime(gp);

        bool decreaseScale = gpKeyIsPressed(gp, GP_KEY_L);
        bool increaseScale = gpKeyIsPressed(gp, GP_KEY_K);

        if (decreaseScale || increaseScale)
        {
            if (decreaseScale && scale > 1)
                scale /= 2; 
            if (increaseScale && scale < 32)
                scale *= 2; 

            bufferWidth  = width / scale;
            bufferHeight = height / scale;
            
            pixels = realloc(pixels, bufferWidth * bufferHeight * sizeof(color_t));
            invertedPixels = realloc(invertedPixels, bufferWidth * bufferHeight * sizeof(color_t));

            screen.texture.width = bufferWidth;
            screen.texture.height = bufferHeight;
            gpTextureUpdate(gp, screen.texture, NULL);
        }

        inputs.width = bufferWidth;
        inputs.height = bufferHeight;
        outputs.pixels = pixels;

        draw_update(&draw, &inputs, &outputs);

        // Render game
        gpDrawBegin(gp);
        gpFramebufferDrawBegin(gp, screen);
        gpDrawClearBackground(gp, (GPColor){0.2f, 0.2f, 0.2f, 1.f});

        // Draw here!
        invertPixels(invertedPixels, pixels, inputs.width, inputs.height);

        gpTextureUpdate(gp, screen.texture, (GPColor*)invertedPixels);
        
        gpFramebufferDrawEnd(gp);

        gpDrawTextureEx2(gp, screen.texture, (GPRect){0.f, 0.f, bufferWidth, bufferHeight}, (GPRect){ 0.f, 0.f, width, height }, GP_CWHITE);

        draw_render(gp, font, &draw);
        gpDrawText(gp, font, (GPVector2){width - 160, height - 2 * 32.f}, (GPColor){1.f, 1.f, 0.f, 1.f}, "FPS %.2f", 1.f / inputs.deltaTime);
        gpDrawText(gp, font, (GPVector2){width - 220, height - 1 * 32.f}, (GPColor){1.f, 1.f, 0.f, 1.f}, "%dx%d (K/L)", bufferWidth, bufferHeight, scale);
        gpDrawEnd(gp);
    }

    free(pixels);
    free(invertedPixels);

    // Shutdown system
    gpFontUnload(gp, font);
    gpFramebufferUnload(gp, screen);
    gpShutdown(gp);
    return 0;
}

