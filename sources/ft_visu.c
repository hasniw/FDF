/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:27 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/24 00:17:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    fill_pixel(t_image *image, int x, int y, int color)
{
        if (x < 0 || x >= image->width || y < 0 || y >= image->height)
                return ;
        *(int *)(image->img + ((x + y * image->width) * image->bpp / 8)) = color;
}

// void set_line(t_line *line)
// {
//     line->x1 = 0;
//     line->y1 = 0;
//     line->x2 = 0;
// 	line->y2 = 0;
// 	line->line_x = 0;
// 	line->line_y = 0;
// 	line->dx = 0;
// 	line->dy = 0;
// 	line->xinc = 0;
// 	line->yinc = 0;
// 	line->cumul = 0;
// }

void    create_line(t_args *args, t_point *position, t_image *image)
{
    int i;
    t_line line;

    // set_line(&line);
    i = -1;

    while (++i < args->nb_point)
    {
        ft_altitude_i(position[i], position[i + 1], &line, *args);
        fill_pixel(image, line.line_x, line.line_y, 255255);
        put_line(&line, args, image);
    }
    mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, image->ptr, 0, 0);
    printf("!!!\n");
    // (void) image;
}

int     create_image(t_image *image, t_args *args)
{
    // prinstf("%p\n", args->mlx_ptr);
    if (!(image->ptr = mlx_new_image(args->mlx_ptr, 50, 60)))
    {
        printf("yo");
        return (-1);
    }
    printf("image\n");
   if (!(image->img = mlx_get_data_addr(image->ptr,
       &(image->bpp), &(image->line_size), &(image->endian))))
       return (-1);
    image->width = args->x_max + 50;
    image->height = args->y_max + 50;
    return (0);
}

int     create_window(t_args *args)
{
    args->mlx_ptr = mlx_init();
    if (!(args->win_ptr = mlx_new_window(args->mlx_ptr,
     WIDTH, HEIGHT, "Window -> Frichti")))
        return (-1);
    return (0);
}