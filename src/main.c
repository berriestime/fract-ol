/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:20:01 by dmorrige          #+#    #+#             */
/*   Updated: 2020/03/02 14:04:36 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef int (*ORNUL)();

void render(t_frct *fractal)
{
    int x = 0;
    int y = 0;
    while (x != WIDTH)
    {
        y = 0;
        while (y != HEIGHT)
        {
            burningship(fractal, x, y);
            // julia(fractal, x, y);
            // mandelbrot(fractal, x, y);
            y++;
        }
        x++;
    }

    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.image, 0, 0);
}

void ft_close(void)
{
    exit(0);
}

int keyevent(int keycode, t_frct *fractal)
{
    if (keycode == 53)
        ft_close();
    else if (keycode == 69) // zoom into
    {
        fractal->zoom -= (fractal->zoom * 0.05f);
        fractal->offset_x = -(WIDTH / 2) * fractal->zoom;
        fractal->offset_y = -(HEIGHT / 2) * fractal->zoom;
    }
    else if (keycode == 78) // zoom out
    {
        fractal->zoom += (fractal->zoom * 0.05f);
        fractal->offset_x = -(WIDTH / 2) * fractal->zoom;
        fractal->offset_y = -(HEIGHT / 2) * fractal->zoom;
    }
    else if (keycode == 126) // upward
        fractal->move_y -= 4.5f * fractal->zoom;
    else if (keycode == 125) // downward
        fractal->move_y += 4.5f * fractal->zoom;
    else if (keycode == 124) // right
        fractal->move_x += 4.5f * fractal->zoom;
    else if (keycode == 123) // left
        fractal->move_x -= 4.5f * fractal->zoom;
    else if (keycode == 15) // reset
        init_fractal(fractal);
    else if (keycode == 24 && fractal->max_iter < 1000) // +
        fractal->max_iter += 10;
    else if (keycode == 27 && fractal->max_iter > 10) // -
        fractal->max_iter -= 10;
    else if (keycode == 49) // space
        fractal->stop_julia_moving = (fractal->stop_julia_moving == 1 ? 0 : 1);

    mlx_clear_window(fractal->mlx, fractal->win);
    render(fractal);
    return (0);
}

void    mandelbrot(t_frct *fractal, const int x, const int y)
{
    float x1;
    float y1;
    float zi;
    float cr;
    int iter;
    float tmp;

    iter = 0;
    x1 = x * fractal->zoom + fractal->offset_x + fractal->move_x;
    y1 = y * fractal->zoom + fractal->offset_y + fractal->move_y;
    zi = 0.f;
    cr = 0.f;
    while (zi * zi + cr * cr <= 4 && iter < fractal->max_iter)
    {
        tmp = zi * zi - cr * cr + x1;
        cr = 2 * zi * cr + y1;
        zi = tmp;
        iter++;
    }
    if (iter >= fractal->max_iter)
        fractal->img.data[x + y * WIDTH] = 0x00000000;
    else
        fractal->img.data[x + y * WIDTH] = 0x0004f0af * iter;
}

void burningship(t_frct *fractal, const int x, const int y)
{
    float z_r;
    float z_i;
    float tmp;
    int iter;
    float c_r;
    float c_i;

    iter = 0;
    z_r = 0;
    z_i = 0;
    c_r = x * fractal->zoom + fractal->offset_x + fractal->move_x;
    c_i = y * fractal->zoom + fractal->offset_y + fractal->move_y;
    while (z_i * z_i + z_r * z_r <= 4 && iter < fractal->max_iter)
    {
        tmp = z_r;
		z_r = fabs(tmp * tmp) - z_i * z_i + c_r;
		z_i = 2 * fabs(tmp * z_i) + c_i;
        iter++;
    }
    if (iter >= fractal->max_iter)
        fractal->img.data[WIDTH * y + x] = 0x00000000;
    else
        fractal->img.data[WIDTH * y + x] = 0x00120913 * iter;
}

void julia(t_frct *fractal, const int x, const int y)
{
    float x1;
    float y1;
    int iter;
    float tmp = 0.f;

    iter = 0;
    x1 = x * fractal->zoom + fractal->offset_x + fractal->move_x;
    y1 = y * fractal->zoom + fractal->offset_y + fractal->move_y;
    while (x1 * x1 + y1 * y1 <= 4 && iter < fractal->max_iter)
    {
        tmp = y1  ;
		y1 = y1 * y1 - x1 * x1 + fractal->mouse_x;
		x1 = 2.0 * tmp * x1 + fractal->mouse_y;
        iter++;
    }
    if (iter >= fractal->max_iter)
        fractal->img.data[WIDTH * y + x] = 0x00000000;
    else
        fractal->img.data[WIDTH * y + x] = 0x0004f0af * iter;
}

void init_mlx(t_frct *fractal)
{
     if (!(fractal->mlx = mlx_init()))
        exit(1);
    if (!(fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "OCHKO")))
        exit(1);
    int bpp = 0; //bits per pixels
    int endian = 0;
    int linesize = 0; //for retina width * 4
  
    fractal->img.image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT); //инициализирует image 
    fractal->img.data = (int *)mlx_get_data_addr(fractal->img.image, &bpp, &linesize, &endian); //массив пикселей
}

int				mouse_event(int x, int y, t_frct *fractal)
{
	if (x > WIDTH || y >= HEIGHT || x < 0 || y < 0 || fractal->stop_julia_moving)
		return (0);
	fractal->mouse_x = x * fractal->zoom;
	fractal->mouse_y = y * fractal->zoom;
    render(fractal);
	return (0);
}

void init_fractal(t_frct *fractal)
{
    fractal->zoom = 0.005f;
    fractal->offset_x = -(WIDTH / 2) * fractal->zoom;
    fractal->offset_y = -(HEIGHT / 2) * fractal->zoom;
    fractal->move_x = 0.f;
    fractal->move_y = 0.f;
    fractal->max_iter = 50;
    fractal->stop_julia_moving = 0;
    fractal->mouse_x = 0.f;
    fractal->mouse_y = 0.f;
}

int main()
{
    t_frct fractal;

    init_mlx(&fractal);
    init_fractal(&fractal);
    render(&fractal);
    mlx_hook(fractal.win, 17, 0, (ORNUL) ft_close, 0);
    mlx_hook(fractal.win, 2, 0, keyevent, &fractal);
    mlx_hook(fractal.win, 6, 0, mouse_event, &fractal);
    mlx_loop(fractal.mlx);
    return (0);
}