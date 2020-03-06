#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "../lib/minilibx_macos/mlx.h"

#define WIDTH 720
#define HEIGHT 480

typedef struct s_image
{
            void *image;
            int *data;
}              t_image;

typedef struct s_ftct
{
    void *mlx;
    void *win;
    t_image img;
    float offset_x;
    float offset_y;
    float move_x;
    float move_y;
    float mouse_x;
    float mouse_y;
    float zoom;
    int max_iter;
    int stop_julia_moving;
    int name;
}               t_frct;

void    init_fractal(t_frct *fractal);
void    mandelbrot(t_frct *fractal, const int x, const int y);
void    julia(t_frct *fractal, const int x, const int y);
void    burningship(t_frct *fractal, const int x, const int y);

#endif
