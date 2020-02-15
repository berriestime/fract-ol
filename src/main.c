/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:20:01 by dmorrige          #+#    #+#             */
/*   Updated: 2020/02/16 00:18:22 by dmorrige         ###   ########.fr       */
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
    int i = 0;
    int j = 0;
    while (i < WIDTH) {
        j = 0;
        while (j < HEIGHT) {
            int i2 = i % (255 * 2);
            int j2 = j % (255 * 2);
            int gb = 0;
            int ar = 0;
            if (i2 > 254) {
                gb = 255 - i % 255;
            } else {
                gb = i % 255;
            }
            if (j2 > 254) {
                ar = 255 - j % 255;
            } else {
                ar = j % 255;
            }
            // data[j * WIDTH + i] = (gb * 0x00000001 + ar * 0x00000100 + (gb % (ar + 1)) * 0x00000100) & 0x00ffffff;
            data[j * WIDTH + i] = (gb * gb * 0x00000001 + ar * 0x00000100 + (gb % (ar + 1)) * 0x00000100) & 0x00ffffff;
            // if (data[j * WIDTH + i] > 0x00ffffff) {
            //     printf("%x\n", data[j * WIDTH + i]);
            // }
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_hook(win, 17, 0, (ORNUL) ft_close, 0);
    mlx_hook(win, 2, 0, keyevent, 0);
    mlx_loop(mlx);
    return (0);
}