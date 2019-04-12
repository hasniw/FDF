/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 13:58:21 by wahasni           #+#    #+#             */
/*   Updated: 2019/02/04 19:24:13 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "../libft/libft.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	del_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*line;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	//	ligne(12, 45, 410, 398);
	int dx,dy,i,xinc,yinc,cumul,x,y,xi,yi,xf,yf,j;
	xi = 12;
	yi = 15;
	xf = 410;
	yf = 389;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = ft_abs(dx);
	dy = ft_abs(dy);
	mlx_pixel_put(mlx_ptr , win_ptr, x, y, 255255255);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 1;
		while (j <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(mlx_ptr , win_ptr, x, y, 255255255);
			j++;
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (j <= dy)
		{
			y += yinc;
			cumul += dx;
			if ( cumul >= dy )
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(mlx_ptr , win_ptr, x, y, 255255255);
			j++;
		}
	}
	mlx_key_hook(win_ptr, del_key, (void *)0);
	mlx_loop(mlx_ptr); // Demande a Mac OS de dessiner ce que l'on veut cad
	// Fenetre Et gere mouvement souris/clavier
}
