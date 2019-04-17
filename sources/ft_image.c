/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:27 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/17 19:45:49 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void    fill_pixel(char *my_image_string, int x, int y, int color)
// {

// }

int     create_image(t_image *image, t_args *args)
{
    // printf("%p\n", args->mlx_ptr);
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
     1800, 1600, "Window -> Frichti")))
        return (-1);
    return (0);
}