/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:05:40 by dmorrige          #+#    #+#             */
/*   Updated: 2020/03/08 00:04:03 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	init_mlx(t_frct *fractal)
{
	int	bpp;
	int	endian;
	int	linesize;

	if (!(fractal->mlx = mlx_init()))
		exit(1);
	if (!(fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "<3")))
		exit(1);
	bpp = 0;
	endian = 0;
	linesize = 0;
	fractal->img.image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->img.data = (int *)mlx_get_data_addr(fractal->img.image, \
							&bpp, &linesize, &endian);
}

void	init_fractal(t_frct *fractal)
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

void	render(t_frct *fractal)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x != WIDTH)
	{
		y = 0;
		while (y != HEIGHT)
		{
			if (fractal->name == 0)
				mandelbrot(fractal, x, y);
			else if (fractal->name == 1)
				julia(fractal, x, y);
			else if (fractal->name == 2)
				burningship(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.image, \
							0, 0);
}

void	second_keyevent(int keycode, t_frct *fractal)
{
	if (keycode == 126)
		fractal->move_y -= 4.5f * fractal->zoom;
	else if (keycode == 125)
		fractal->move_y += 4.5f * fractal->zoom;
	else if (keycode == 124)
		fractal->move_x += 4.5f * fractal->zoom;
	else if (keycode == 123)
		fractal->move_x -= 4.5f * fractal->zoom;
	else if (keycode == 15)
		init_fractal(fractal);
	else if (keycode == 24 && fractal->max_iter < 1000)
		fractal->max_iter += 10;
	else if (keycode == 27 && fractal->max_iter > 10)
		fractal->max_iter -= 10;
	else if (keycode == 49)
		fractal->stop_julia_moving = (fractal->stop_julia_moving == 1 ? 0 : 1);
}

int		keyevent(int keycode, t_frct *fractal)
{
	if (keycode == 53)
		ft_close();
	else if (keycode == 69)
	{
		fractal->zoom -= (fractal->zoom * 0.05f);
		fractal->offset_x = -(WIDTH / 2) * fractal->zoom;
		fractal->offset_y = -(HEIGHT / 2) * fractal->zoom;
	}
	else if (keycode == 78)
	{
		fractal->zoom += (fractal->zoom * 0.05f);
		fractal->offset_x = -(WIDTH / 2) * fractal->zoom;
		fractal->offset_y = -(HEIGHT / 2) * fractal->zoom;
	}
	else
		second_keyevent(keycode, fractal);
	mlx_clear_window(fractal->mlx, fractal->win);
	render(fractal);
	return (0);
}
