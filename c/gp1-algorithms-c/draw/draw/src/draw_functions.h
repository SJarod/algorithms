
#include "draw.h"

// Fill entire buffer with color
void draw_clear(image_t img, color_t color);

// Draw random colors for every pixels in the buffer
void draw_noise(image_t img);

// Draw a single point in the buffer
// We need to compute the index from x,y,width
// WARNING! This function has to check if x and y are valid !
void draw_point(image_t img, int x, int y, color_t color);

void draw_line_naive(image_t img, int x1, int y1, int x2, int y2, color_t color);

void draw_line_bresenham(image_t img, int x1, int y1, int x2, int y2, color_t color);
