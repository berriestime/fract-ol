/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:20:01 by dmorrige          #+#    #+#             */
/*   Updated: 2020/02/26 21:20:54 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"

#define WIDTH 255 * 4
#define HEIGHT 255 * 2

typedef int (*ORNUL)();

void ft_close(void)
{
    exit(0);
}

int keyevent(int keycode, void *param)
{
    (void )param;
    if (keycode == 53)
        ft_close();
    return (0);
}

int key_event(int keycode, void *param);

int mouse_event(int x, int y);

void    render(int *data, int x, int y)
{
    float x1;
    float y1;
    float zi;
    float cr;
    int iter;
    int max_iter;
    float tmp;

    iter = 0;
    max_iter = 50;
    x1 = x * 0.002f;
    y1 = y * 0.002f;
    zi = 0.f;
    cr = 0.f;
    while (zi * zi + cr * cr <= 4 && iter < max_iter)
    {
        tmp = zi * zi - cr * cr + x1;
        cr = 2 * zi * cr + y1;
        zi = tmp;
        iter++;
    }
    if (iter >= max_iter)
        data[x + y * WIDTH] = 0x00000000;
    else
        data[x + y * WIDTH] = 0x00f0f0f0;
}

int main()
{
    void *mlx;
    void *win;

    if (!(mlx = mlx_init()))
        return (1);
    if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, "OCHKO")))
        return (1);
    void *image;
    int *data;
    int bpp = 0; //bits per pixels
    int endian = 0;
    int linesize = 0; //for retina width * 4
    int x;
    int y;

    x = 0;
    y = 0;
    image = mlx_new_image(mlx, WIDTH, HEIGHT); //инициализирует image 
    data = (int *)mlx_get_data_addr(image, &bpp, &linesize, &endian); //массив пикселей
    while (x != WIDTH)
    {
        y = 0;
        while (y != HEIGHT)
        {
            render(data, x, y);
            y++;
        }
        x++;
    }

    mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_hook(win, 17, 0, (ORNUL) ft_close, 0);
    mlx_hook(win, 2, 0, keyevent, 0);
    mlx_loop(mlx);
    return (0);
}