
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "draw_functions.h"

const color_t CWHITE = { 1.f, 1.f, 1.f, 1.f };

static void swap(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void draw_clear(image_t img, color_t color)
{
    int max = img.height * img.width;

    for (int i = 0; i < max; ++i)
    {
        img.pixels[i] = color;
    }
}

void draw_point(image_t img, int x, int y, color_t color)
{
    if (x >= img.width || y >= img.height || x < 0 || y < 0)
        return;

    int index = x + y * img.width;
    img.pixels[index] = color;
}

void draw_noise(image_t img)
{
    int max = img.height * img.width;

    for (int i = 0; i < max; ++i)
    {
        float c = ((rand() % 1000) + 1) / 1000.f;
        img.pixels[i].r = c;//((rand() % 1000) + 1) / 1000.f;
        img.pixels[i].g = c;//((rand() % 1000) + 1) / 1000.f;
        img.pixels[i].b = c;//((rand() % 1000) + 1) / 1000.f;
        img.pixels[i].a = 1.f;
    }
}

void draw_line_naive(image_t img, int x0, int y0, int x1, int y1, color_t color)
{
    if (x0 == x1)
        return;

    int minX, minY, maxX, maxY;

    minX = x1;
    minY = y1;
    maxX = x0;
    maxY = y0;

    if (x0 < x1)
    {
        swap(&x0, &x1);
	    swap(&y0, &y1);
    }

    float m = (maxY - minY) / (float)(maxX - minX);

    for (int x = minX; x < maxX; ++x)
    {
        int y = (x - minX) * m + minY;
        draw_point(img, x, y, color);
    }
}

void draw_line(image_t img, int x0, int y0, int x1, int y1, color_t color)
{
    draw_line_bresenham(img, x0, y0, x1, y1, color);
}

void draw_koch_branch(image_t img, int x0, int y0, int x1, int y1, int depth, color_t color)
{
    if (depth == 0)
    {
        draw_line(img, x0, y0, x1, y1, color);
        return;
    }

    //point A
    int x = x0;
    int y = y0;

    //point B
    int a = x1;
    int b = y1;

    //vector AB
    float Vx = a - x;
    float Vy = b - y;
    if (Vx == 0 && Vy == 0)
        return;

    //point C
    float e = Vx / 3;
    float f = Vy / 3;

    //point D
    float g = 2 * e + x;
    float h = 2 * f + y;

    //point F
    float v = Vx / 2 + x;
    float w = Vy / 2 + y;

    //length of AB
    float AB = sqrt(Vx * Vx + Vy * Vy);
    //length of EF
    float EF = (AB / 6) * sqrt(3);

    //point E
    float i = v + EF * (-Vy / AB);
    float j = w + EF * (Vx / AB);

    draw_koch_branch(img, x, y, e + x, f + y, depth - 1, color);
    draw_koch_branch(img, g, h, a, b, depth - 1, color);
    draw_koch_branch(img, e + x, f + y, i, j, depth - 1, color);
    draw_koch_branch(img, i, j, g, h, depth - 1, color);
}

void draw_fractal_squares(image_t img, int centerX, int centerY, float sideLength, int depth, float angleOffset, color_t color)
{
    float cosa = cosf(angleOffset);
    float sina = sinf(angleOffset);

    float Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    Ax = centerX - sideLength / 2 * cosa;
    Ay = centerY - sideLength / 2 * sina;
    Bx = centerX + sideLength / 2 * sina;
    By = centerY - sideLength / 2 * cosa;
    Cx = centerX + sideLength / 2 * cosa;
    Cy = centerY + sideLength / 2 * sina;
    Dx = centerX - sideLength / 2 * sina;
    Dy = centerY + sideLength / 2 * cosa;

    draw_line(img, Ax, Ay, Bx, By, color);
    draw_line(img, Dx, Dy, Cx, Cy, color);
    draw_line(img, Ax, Ay, Dx, Dy, color);
    draw_line(img, Bx, By, Cx, Cy, color);

    if (depth > 0)
    {
        draw_fractal_squares(img, Ax, Ay, sideLength / 2, depth - 1, angleOffset, color);
        draw_fractal_squares(img, Bx, By, sideLength / 2, depth - 1, angleOffset, color);
        draw_fractal_squares(img, Cx, Cy, sideLength / 2, depth - 1, angleOffset, color);
        draw_fractal_squares(img, Dx, Dy, sideLength / 2, depth - 1, angleOffset, color);
        return;
    }
}

void draw_polygon(image_t img, int nGones, float radius, float angleOffset, float posOffsetX, float posOffsetY, color_t color)
{

}
