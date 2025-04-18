#include <stdlib.h>
#include <math.h>

#include "draw.h"
#include "draw_functions.h"

typedef void (*draw_line_func)(image_t, int, int, int, int, color_t);

static int euclidean_mod(int a, int b)
{
    return ((a % b) + b) % b;
}

void draw_init(draw_t* draw, const inputs_t* inputs)
{
    // Init all to zero
    *draw = (draw_t){};
    draw->state = DS_POINTS; // Change starting state here
}

void draw_destroy(draw_t* draw)
{
    // Nothing to do
}

void test_draw_points(image_t img, double time)
{
    int step = 8;
    int ct = cosf(time*8) * step/2.f;
    int st = sinf(time*8) * step/2.f;
    for (int y = 0; y <= img.height/step; ++y)
    {
        for (int x = 0; x <= img.width/step; ++x)
        {
            int offsetX = (x % 2) == 0 ? 0 : ct;
            int offsetY = (y % 2) == 0 ? 0 : st;
            draw_point(img, offsetX + x * step, offsetY + y * step, CWHITE);
        }
    }
}

void test_draw_lines(image_t img, float phase, draw_line_func drawLineFunc)
{
    int radius = img.width / 4;

    int x1 = img.width / 2.f;
    int y1 = img.height / 2.f;
    int x2 = x1 + cosf(phase) * radius;
    int y2 = y1 + sinf(phase) * radius;

    drawLineFunc(img, x1, y1, x2, y2, CWHITE);
}

void draw_update(draw_t* draw, const inputs_t* inputs, outputs_t* outputs)
{
    image_t img = { .pixels = outputs->pixels, .width = inputs->width, .height = inputs->height };

    draw_clear(img, (color_t){0.f, 0.f, 0.f, 1.f});

    // Prev/next state
    {
        int previousState = draw->state;
        if (inputs->prevState)
            draw->state--;
        if (inputs->nextState)
            draw->state++;
        draw->state = euclidean_mod(draw->state, DS_COUNT);

        if (inputs->phaseUp)
            draw->phase += 2.f * inputs->deltaTime;
        if (inputs->phaseDown)
            draw->phase -= 2.f * inputs->deltaTime;

        if (draw->state != previousState)
            draw_clear(img, (color_t){0.f, 0.f, 0.f, 1.f});
    }

    switch (draw->state)
    {
    case DS_NOTHING:
        break;
    case DS_NOISE:
        draw_noise(img);
        break;
    case DS_POINTS:
        test_draw_points(img, inputs->time);
        break;
    case DS_LINES_NAIVE:
        test_draw_lines(img, draw->phase, draw_line_naive);
        break;
    case DS_LINES_BRESENHAM:
        test_draw_lines(img, draw->phase, draw_line_bresenham);
        break;

    default:;
    }
}

