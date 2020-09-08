#pragma once

#include <stdbool.h>

typedef struct color_t
{
    float r;
    float g;
    float b;
    float a;
} color_t;

const color_t CWHITE;

typedef struct inputs_t
{
    float deltaTime;
    double time;
    bool nextState;
    bool prevState;
    bool phaseDown;
    bool phaseUp;
    bool depthDown;
    bool depthUp;

    int width;
    int height;
} inputs_t;

typedef struct outputs_t
{
    color_t* pixels;
} outputs_t;

typedef struct image_t
{
    int width;
    int height;
    color_t* pixels;
} image_t;

typedef enum draw_state_e
{
    DS_NOTHING,
    DS_NOISE,
    DS_POINTS,
    DS_LINES_NAIVE,
    DS_LINES_BRESENHAM,
    DS_KOCH_BRANCH,
    DS_KOCH_SNOWFLAKE,
    DS_KOCH_ON_SPIRAL,

    DS_COUNT
} draw_state_e;

typedef struct draw_t
{
    draw_state_e state;
    float phase;
    int depth;
} draw_t;

void draw_init(draw_t* draw, const inputs_t* inputs);
void draw_destroy(draw_t* draw);
void draw_update(draw_t* draw, const inputs_t* inputs, outputs_t* outputs);
