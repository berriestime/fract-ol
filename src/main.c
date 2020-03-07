/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:10:04 by dmorrige          #+#    #+#             */
/*   Updated: 2020/03/08 00:10:09 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	check(char *av, t_frct *fractal)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		fractal->name = 0;
	else if (ft_strcmp(av, "julia") == 0)
		fractal->name = 1;
	else if (ft_strcmp(av, "burningship") == 0)
		fractal->name = 2;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
		exit(1);
	}
}

int		main(int ac, char **av)
{
	t_frct fractal;

	if (ac != 2)
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
		exit(1);
	}
	check(av[1], &fractal);
	init_mlx(&fractal);
	init_fractal(&fractal);
	render(&fractal);
	mlx_hook(fractal.win, 17, 0, (t_mlx_hook)ft_close, 0);
	mlx_hook(fractal.win, 2, 0, keyevent, &fractal);
	mlx_hook(fractal.win, 6, 0, mouse_event, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
