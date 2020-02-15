/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:20:01 by dmorrige          #+#    #+#             */
/*   Updated: 2020/02/16 00:14:35 by dmorrige         ###   ########.fr       */
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

typedef struct s_ochko {
    void *win;
    void *mlx;
    void *image;
    int *data;
} t_ochko;

void ft_close(void)
{
    exit(0);
}

void RENDER_OCHKA(t_ochko *to_samoe_ochko, double Ox, double Oy) {
    double Px = 0;
    double Py = 0;
    while (Px < WIDTH) {
        Py = 0;
        while (Py < HEIGHT) {
            double x0 = (Ox * 0.1f + Px) * 0.001f;
            double y0 = (Oy * 0.1f + Py) * 0.001f;
            double x = 0;
            double y = 0;
            double step = 0;
            double max_step = 100;
            while (x * x + y * y <= 4 && step < max_step) {
                double tmp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = tmp;
                step++;
            }

            to_samoe_ochko->data[(int)(Py * WIDTH + Px)] = step * 2 * 0x00010101;

            Py++;
        }
        Px++;
    }
}

// int ft_move_mouse(int button, int x,int y, t_ochko *tot_prekrasnyi_struct) {
int ft_move_mouse(int x, int y, t_ochko *tot_prekrasnyi_struct) {
    printf("%i %i\n", x, y);
    RENDER_OCHKA(tot_prekrasnyi_struct, x, y);
    mlx_put_image_to_window(tot_prekrasnyi_struct->mlx, tot_prekrasnyi_struct->win, tot_prekrasnyi_struct->image, 0, 0);
    return (0);
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
    t_ochko *moi_prekrasnyi_struct;
    void *mlx;
    void *win;

    moi_prekrasnyi_struct = malloc(sizeof(t_ochko));

    if (!(moi_prekrasnyi_struct->mlx = mlx_init()))
        return (1);
    if (!(moi_prekrasnyi_struct->win = mlx_new_window(moi_prekrasnyi_struct->mlx, WIDTH, HEIGHT, "OCHKO")))
        return (1);
    void *image;
    int *data;
    int bpp = 0; //beats per pixels 
    int endian = 0;
    int linesize = 0; // for retina width * 4

    moi_prekrasnyi_struct->image = mlx_new_image(moi_prekrasnyi_struct->mlx, WIDTH, HEIGHT); //инициализирует image 
    moi_prekrasnyi_struct->data = (int *)mlx_get_data_addr(moi_prekrasnyi_struct->image, &bpp, &linesize, &endian); //массив пикселей
    // int x = 0;
    // int y;
    // int maxIter = 50;
    // while (x < WIDTH)
    // {
    //     y = 0;
    //     while (y < HEIGHT)
    //     {
    //         float x0 = x * 0.05f;
    //         float y0 = y * 0.05f;
    //         float zi, zr, cr, ci = 0.f;
    //         int iter = 0;

    //         while (zi * zi + cr * cr <= 4 && iter < maxIter)
    //         {
    //             float tmp = zi * zi - cr * cr + x0;
    //             cr = 2 * cr * zi + y0;
    //             zi = tmp;
    //             iter++;
    //         }
    //         if (iter >= maxIter - 1)
    //             data[x + y * WIDTH] = 0x0;
    //         else
    //             data[x + y * WIDTH] = 0x00ff00ff;
    //         y++;
    //     }
    //     x++;
    // }
    RENDER_OCHKA(moi_prekrasnyi_struct, 0, 0);

    // mlx_mouse_hook(moi_prekrasnyi_struct->win, ft_move_mouse, moi_prekrasnyi_struct);
    mlx_hook(moi_prekrasnyi_struct->win, 6, 0, ft_move_mouse, moi_prekrasnyi_struct);

    // while (i < WIDTH) {
    //     j = 0;
    //     while (j < HEIGHT) {
    //         int i2 = i % (255 * 2);
    //         int j2 = j % (255 * 2);
    //         int gb = 0;
    //         int ar = 0;
    //         if (i2 > 254) {
    //             gb = 255 - i % 255;
    //         } else {
    //             gb = i % 255;
    //         }
    //         if (j2 > 254) {
    //             ar = 255 - j % 255;
    //         } else {
    //             ar = j % 255;
    //         }
    //         // data[j * WIDTH + i] = (gb * 0x00000001 + ar * 0x00000100 + (gb % (ar + 1)) * 0x00000100) & 0x00ffffff;
    //         data[j * WIDTH + i] = (gb * gb * 0x00000001 + ar * 0x00000100 + (gb % (ar + 1)) * 0x00000100) & 0x00ffffff;
    //         // if (data[j * WIDTH + i] > 0x00ffffff) {
    //         //     printf("%x\n", data[j * WIDTH + i]);
    //         // }
    //         j++;
    //     }
    //     i++;
    // }
    mlx_put_image_to_window(moi_prekrasnyi_struct->mlx, moi_prekrasnyi_struct->win, moi_prekrasnyi_struct->image, 0, 0);
    mlx_hook(moi_prekrasnyi_struct->win, 17, 0, (ORNUL) ft_close, 0);
    mlx_hook(moi_prekrasnyi_struct->win, 2, 0, keyevent, 0);
    mlx_loop(moi_prekrasnyi_struct->mlx);
    return (0);
}