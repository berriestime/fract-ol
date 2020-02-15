/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:20:01 by dmorrige          #+#    #+#             */
/*   Updated: 2020/02/16 00:19:32 by dmorrige         ###   ########.fr       */
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
    int bpp = 0; //beats per pixels 
    int endian = 0;
    int linesize = 0; // for retina width * 4

    image = mlx_new_image(mlx, WIDTH, HEIGHT); //инициализирует image 
    data = (int *)mlx_get_data_addr(image, &bpp, &linesize, &endian); //массив пикселей
    data[HEIGHT * WIDTH / 2 + WIDTH / 2] = 0x00ffffff;
    mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_hook(win, 17, 0, (ORNUL) ft_close, 0);
    mlx_hook(win, 2, 0, keyevent, 0);
    mlx_loop(mlx);
    return (0);
}