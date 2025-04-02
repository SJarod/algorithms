
#include <stdlib.h>
#include <stdio.h>

#include "draw_functions.h"

const color_t CWHITE = {1.f, 1.f, 1.f, 1.f};

// Fill entire buffer with color
void draw_clear(image_t img, color_t color)
{
    int max = img.height * img.width;

    for (int i = 0; i < max; ++i)
    {
        img.pixels[i] = color;
    }
}

// Draw a single point in the buffer
// We need to compute the index from x,y,width
// WARNING! This function has to check if x and y are valid !
void draw_point(image_t img, int x, int y, color_t color)
{
    if (x > img.width || y > img.height)
        return;

    int index = x + y * img.width;
    img.pixels[index] = color;
}

void draw_line_naive(image_t img, int x1, int y1, int x2, int y2, color_t color)
{
    if (x1 == x2)
        return;

    int minX, minY, maxX, maxY;

    if (x1 < x2)
    {
        minX = x1;
        minY = y1;
        maxX = x2;
        maxY = y2;
    }
    else
    {
        minX = x2;
        minY = y2;
        maxX = x1;
        maxY = y1;
    }

    float m = (maxY - minY) / (float)(maxX - minX);

    for (int x = minX; x < maxX; ++x)
    {
        int y = (x - minX) * m + minY;
        draw_point(img, x, y, color);
    }
}

void draw_line_bresenham(image_t img, int x1, int y1, int x2, int y2, color_t color)
{
    if (x1 == x2)
        return;

    int minX, maxX, minY, maxY, octant;

    if (x1 < x2)
    {
        minX = x1;
        minY = y1;
        maxX = x2;
        maxY = y2;
    }
    else
    {
        minX = x2;
        minY = y2;
        maxX = x1;
        maxY = y1;
    }

    int dx = maxX - minX;
    int dy = maxY - minY;

    if (abs(dx) >= abs(dy) && dy >= 0)
        octant = 1;
    else if (abs(dx) >= abs(dy) && dy < 0)
        octant = 4;
    else if (abs(dx) < abs(dy) && dy >= 0)
        octant = 2;
    else if (abs(dx) < abs(dy) && dy < 0)
        octant = 3;

    if (octant == 1)
    {
        int deltaE = 2 * dy;
        int deltaNE = 2 * (dy - dx);
        int dp = 2 * dy - dx;

        int y = minY;

        for (int x = minX; x < maxX; ++x)
        {
            draw_point(img, x, y, color);
            fprintf(stderr, "octant 1\n");

            if (dp <= 0)
                dp += deltaE;
            else
            {
                y++;
                dp += deltaNE;
            }
        }
    }
    else if (octant == 4)
    {
        dy = -dy;
        int deltaE = 2 * dy;
        int deltaSE = 2 * (dy - dx);
        int dp = 2 * dy - dx;

        int y = minY;

        for (int x = minX; x < maxX; ++x)
        {
            draw_point(img, x, y, color);
            fprintf(stderr, "octant 4\n");

            if (dp <= 0)
                dp += deltaE;
            else
            {
                y--;
                dp += deltaSE;
            }
        }
    }
    else if (octant == 2)
    {
        int deltaN = 2 * dx;
        int deltaNE = 2 * (dx - dy);
        int dp = 2 * dx - dy;

        int x = minX;

        for (int y = minY; y < maxY; ++y)
        {
            draw_point(img, x, y, color);
            fprintf(stderr, "octant 2\n");

            if (dp <= 0)
                dp += deltaN;
            else
            {
                x++;
                dp += deltaNE;
            }
        }
    }
    else if (octant == 3)
    {
        dy = -dy;
        int deltaN = 2 * dx;
        int deltaNO = 2 * (dx - dy);
        int dp = 2 * dx - dy;

        int x = maxX;

        for (int y = maxY; y > minY; --y)
        {
            draw_point(img, x, y, color);
            fprintf(stderr, "octant 3\n");

            if (dp <= 0)
                dp += deltaN;
            else
            {
                x--;
                dp += deltaNO;
            }
        }
    }

    fprintf(stderr, "dx = %d\ndy = %d\n\r", dx, dy);
}

// Draw random colors for every pixels in the buffer
void draw_noise(image_t img)
{
    int max = img.height * img.width;

    for (int i = 0; i < max; ++i)
    {
        img.pixels[i].r = rand() % 2;
        img.pixels[i].g = rand() % 2;
        img.pixels[i].b = rand() % 2;
        img.pixels[i].a = 1.f;
    }
}
