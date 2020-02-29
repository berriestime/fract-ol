#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"

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
    float zoom;
    int max_iter;
}               t_frct;

void init_fractal(t_frct *fractal);

#endif
