/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:54:10 by dmorrige          #+#    #+#             */
/*   Updated: 2020/03/08 00:11:15 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 720
# define HEIGHT 480

typedef	int	(*t_mlx_hook)();

typedef	struct	s_image
{
	void		*image;
	int			*data;
}				t_image;

typedef	struct	s_mandelbrot
{
	float		x1;
	float		y1;
	float		zi;
	float		cr;
	int			iter;
	float		tmp;
}				t_mandelbrot;

typedef	struct	s_burningship
{
	float		z_r;
	float		z_i;
	float		tmp;
	int			iter;
	float		c_r;
	float		c_i;
}				t_burningship;

typedef	struct	s_ftct
{
	void		*mlx;
	void		*win;
	t_image		img;
	float		offset_x;
	float		offset_y;
	float		move_x;
	float		move_y;
	float		mouse_x;
	float		mouse_y;
	float		zoom;
	int			max_iter;
	int			stop_julia_moving;
	int			name;
}				t_frct;

void			init_fractal(t_frct *fractal);
void			mandelbrot(t_frct *fractal, const int x, const int y);
void			julia(t_frct *fractal, const int x, const int y);
void			burningship(t_frct *fractal, const int x, const int y);
void			render(t_frct *fractal);
void			init_mlx(t_frct *fractal);
int				keyevent(int keycode, t_frct *fractal);
void			second_keyevent(int keycode, t_frct *fractal);
int				mouse_event(int x, int y, t_frct *fractal);
void			ft_close(void);
void			check(char *av, t_frct *fractal);

#endif
