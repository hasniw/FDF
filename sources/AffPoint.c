/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AffPoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 23:33:40 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/14 21:06:37 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "../libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		del_mouse(int mouse, void *param)
{
	int	x;
	int	y;

	// Soit prendre valeur x = x-mouse ... 
	// Ou dans mlx_pixel_put utiliser x mouse
	// Donc chercgher dans la librairies
	
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 255228225);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*line;

	mlx_ptr = mlx_init();
	win_ptr	= mlx_new_window(mlx ptr, 500, 500, "TEST POUR AFFICHER UN POINT VIA MOUSE");
	mlx_pixel_put(mlx_ptr, win_ptr, 244, 144, 255255000);
	mlx_mouse_hook(win_ptr, del_mouse, (void *)0)
	mlx_loop(mlx_ptr);
}
