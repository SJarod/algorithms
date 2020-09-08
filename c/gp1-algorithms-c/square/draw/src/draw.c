#include <stdlib.h>
#include <math.h>

#include "draw.h"
#include "draw_functions.h"

typedef void (*draw_line_func)(image_t, int, int, int, int, color_t);

static int euclidean_mod(int a, int b)
{
    return ((a % b) + b) % b;
}

static int min(int v, int lo)
{
    return v < lo ? lo : v;
}

static int max(int v, int hi)
{
    return v > hi ? hi : v;
}

static int clamp(int v, int lo, int hi)
{
    return min(max(v, hi), lo);
}

void draw_init(draw_t* draw, const inputs_t* inputs)
{
    // Init all to zero
    *draw = (draw_t){};
    draw->state = DS_POINTS; // Change starting state here
    draw->phase = 1.f;
    draw->depth = 1;
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

float lerp(float x, float y, float a)
{
    return x * (1 - a) + y * a;
}

void test_koch_on_archimedean_spiral(image_t img, float time, float phase, int depth)
{
    float origX = img.width  / 2.f;
    float origY = img.height / 2.f;
    float angleInc = (M_PI * 2.f) / 8;
    float p = 8.f + cosf(time) * 0.5f;
    for (int i = 0; i < 180; ++i)
    {
        float angle0 = phase + i * angleInc;
        float angle1 = angle0 + angleInc;

        float r0 = p * angle0;
        float r1 = p * angle1;

        float x0 = origX + cosf(angle0) * r0;
        float y0 = origY + sinf(angle0) * r0;
        float x1 = origX + cosf(angle1) * r1;
        float y1 = origY + sinf(angle1) * r1;

        //draw_line(img, x0, y0, x1, y1, CWHITE);
        draw_koch_branch(img, x0, y0, x1, y1, depth, CWHITE);
        draw_point(img, x0, y0, (color_t){1.f, 0.f, 0.f, 1.f});
        draw_point(img, x1, y1, (color_t){1.f, 0.f, 0.f, 1.f});
    }
}

void test_koch_snowflake(image_t img, float phase, int depth)
{
    int originX = img.width / 2;
    int originY = img.height / 2;
    float radius = img.height / 2;

    // Triangle points
    int pointsX[3];
    int pointsY[3];
    for (int i = 0; i < 3; ++i)
    {
        pointsX[i] = originX + cosf(phase + i * -M_PI * 2.f / 3.f) * radius;
        pointsY[i] = originY + sinf(phase + i * -M_PI * 2.f / 3.f) * radius;
    }

    draw_koch_branch(img, pointsX[0], pointsY[0], pointsX[1], pointsY[1], depth, CWHITE);
    draw_koch_branch(img, pointsX[1], pointsY[1], pointsX[2], pointsY[2], depth, CWHITE);
    draw_koch_branch(img, pointsX[2], pointsY[2], pointsX[0], pointsY[0], depth, CWHITE);
}

void test_fractal_squares(image_t img, float phase, int depth)
{
    draw_fractal_squares(img, img.width / 2.f, img.height / 2.f, img.height / 2.2f, depth, phase, CWHITE);
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

        if (inputs->depthUp)
            draw->depth += 1;
        if (inputs->depthDown)
            draw->depth -= 1;

        draw->depth = clamp(draw->depth, 0, 5);

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
    case DS_KOCH_BRANCH:
        draw_koch_branch(img, 5, img.height / 2, img.width - 5, img.height / 3, draw->depth, CWHITE);
        break;
    case DS_KOCH_SNOWFLAKE:
        test_koch_snowflake(img, draw->phase, draw->depth);
        break;
    case DS_KOCH_ON_SPIRAL:
        test_koch_on_archimedean_spiral(img, inputs->time, draw->phase, draw->depth);
        break;
    case DS_FRACTAL_SQUARES:
        test_fractal_squares(img, draw->phase, draw->depth);
        break;
    default:;
    }
}

