/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:27 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/20 03:14:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void    fill_pixel(char *my_image_string, int x, int y, int color)
// {

// }

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
    // while (++i < args->nb_point)
    // {
    //     // projection(position[i], position[i + 1], &line, args);
    //     ft_altitude_i(position[i], position[i + 1], &line, *args);
    //     // printf("line->x1 :%d\n", line.x1);
    //     put_line(&line, args);
    // }
    while (++i < args->nb_point)
    {
        ft_altitude_p(position[i], position[i + 1], &line, *args);
        mlx_pixel_put(args->mlx_ptr , args->win_ptr, line.line_x, line.line_y, 255255255);
    }
    printf("!!!\n");
    (void) image;
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
    return (0);
}

int     create_window(t_args *args)
{
    args->mlx_ptr = mlx_init();
    if (!(args->win_ptr = mlx_new_window(args->mlx_ptr,
     500, 700, "Window -> Frichti")))
        return (-1);
    return (0);
}