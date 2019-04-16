/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:27 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/16 23:25:31 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf"

int create_image(t_image *image)
{
    if (!(image->ptr = mlx_new_image(args.mlx_ptr, args.win_x, args.win_y))
        return (-1);
    if (!(image->img = mlx_get_data_addr(image->ptr,
        &(image->bpp), &(image->size_line), &(image->endian))))
        return (-1);
    return (0);
}

int create_window(t_args *args)
{
    args->mlx_ptr = mlx_init();
    if (!(args->win_ptr = mlx_new_window(args->mlx_ptr,
     1800, 1600, "Window -> Frichti")))
        return (-1);
    return (0);
}