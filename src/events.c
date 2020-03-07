/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:05:43 by dmorrige          #+#    #+#             */
/*   Updated: 2020/03/08 00:10:06 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	ft_close(void)
{
	exit(0);
}

void	mandelbrot(t_frct *fractal, const int x, const int y)
{
	t_mandelbrot mndt;

	mndt.iter = 0;
	mndt.x1 = x * fractal->zoom + fractal->offset_x + fractal->move_x;
	mndt.y1 = y * fractal->zoom + fractal->offset_y + fractal->move_y;
	mndt.zi = 0.f;
	mndt.cr = 0.f;
	while (mndt.zi * mndt.zi + mndt.cr * mndt.cr <= 4 && \
			mndt.iter < fractal->max_iter)
	{
		mndt.tmp = mndt.zi * mndt.zi - mndt.cr * mndt.cr + mndt.x1;
		mndt.cr = 2 * mndt.zi * mndt.cr + mndt.y1;
		mndt.zi = mndt.tmp;
		mndt.iter++;
	}
	if (mndt.iter >= fractal->max_iter)
		fractal->img.data[x + y * WIDTH] = 0x00000000;
	else
		fractal->img.data[x + y * WIDTH] = 0x0004f0af * mndt.iter;
}

void	julia(t_frct *fractal, const int x, const int y)
{
	float	x1;
	float	y1;
	int		iter;
	float	tmp;

	tmp = 0.f;
	iter = 0;
	x1 = x * fractal->zoom + fractal->offset_x + fractal->move_x;
	y1 = y * fractal->zoom + fractal->offset_y + fractal->move_y;
	while (x1 * x1 + y1 * y1 <= 4 && iter < fractal->max_iter)
	{
		tmp = y1;
		y1 = y1 * y1 - x1 * x1 + fractal->mouse_x;
		x1 = 2.0 * tmp * x1 + fractal->mouse_y;
		iter++;
	}
	if (iter >= fractal->max_iter)
		fractal->img.data[WIDTH * y + x] = 0x00000000;
	else
		fractal->img.data[WIDTH * y + x] = 0x0004f0af * iter;
}

void	burningship(t_frct *fractal, const int x, const int y)
{
	t_burningship burn;

	burn.iter = 0;
	burn.z_r = 0;
	burn.z_i = 0;
	burn.c_r = x * fractal->zoom + fractal->offset_x + fractal->move_x;
	burn.c_i = y * fractal->zoom + fractal->offset_y + fractal->move_y;
	while (burn.z_i * burn.z_i + burn.z_r * burn.z_r <= 4 && \
			burn.iter < fractal->max_iter)
	{
		burn.tmp = burn.z_r;
		burn.z_r = fabs(burn.tmp * burn.tmp) - burn.z_i * burn.z_i + burn.c_r;
		burn.z_i = 2 * fabs(burn.tmp * burn.z_i) + burn.c_i;
		burn.iter++;
	}
	if (burn.iter >= fractal->max_iter)
		fractal->img.data[WIDTH * y + x] = 0x00000000;
	else
		fractal->img.data[WIDTH * y + x] = 0x00120913 * burn.iter;
}

int		mouse_event(int x, int y, t_frct *fractal)
{
	if (x > WIDTH || y >= HEIGHT || x < 0 || y < 0 \
		|| fractal->stop_julia_moving)
		return (0);
	fractal->mouse_x = x * fractal->zoom;
	fractal->mouse_y = y * fractal->zoom;
	render(fractal);
	return (0);
}
