/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 13:58:21 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/25 00:29:32 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fdf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	del_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

void	put_line(t_line *line, t_args *args, t_image *image)
{
	// void	*mlx_ptr;
	// void	*win_ptr;
	// void	*line;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	//	ligne(12, 45, 410, 398);
	int i,xinc,yinc,cumul,j;
	// xi,yi,xf,yf,x,y,dx,dy,
	// xi = 12;
	// yi = 15;
	// xf = 410;
	// yf = 389;
	// x = xi;
	// y = yi;
	// dx = xf - xi;
	// dy = yf - yi;
	xinc = ( line->dx > 0 ) ? 1 : -1;
	yinc = ( line->dy > 0 ) ? 1 : -1;
	line->dx = ft_abs(line->dx);
	line->dy = ft_abs(line->dy);
	mlx_pixel_put(args->mlx_ptr , args->win_ptr, line->line_x, line->line_y, 255255255);
	// fill_pixel(image, line->line_x, line->line_y, 255255255);
	if (line->dx > line->dy)
	{
		cumul = line->dx / 2;
		i = 1;
		while (j <= line->dx)
		{
			line->line_x += xinc;
			cumul += line->dy;
			if (cumul >= line->dx)
			{
				cumul -= line->dx;
				line->line_y += yinc;
			}
			mlx_pixel_put(args->mlx_ptr , args->win_ptr, line->line_x, line->line_y, 255255255);
			// fill_pixel(image, line->line_x, line->line_y, 255255255);
			j++;
		}
	}
	else
	{
		cumul = line->dy / 2;
		i = 1;
		while (j <= line->dy)
		{
			line->line_y += yinc;
			cumul += line->dx;
			if ( cumul >= line->dy )
			{
				cumul -= line->dy;
				line->line_x += xinc;
			}
			mlx_pixel_put(args->mlx_ptr , args->win_ptr, line->line_x, line->line_y, 255255255);
			// fill_pixel(image, line->line_x, line->line_y, 255255255);
			j++;
		}
	}
	// mlx_key_hook(awin_ptr, del_key, (void *)0);
	// mlx_loop(mlx_ptr); // Demande a Mac OS de dessiner ce que l'on veut cad
	// Fenetre Et gere mouvement souris/clavier
}
