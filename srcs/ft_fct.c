/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 01:45:16 by mnaji             #+#    #+#             */
/*   Updated: 2019/05/08 15:23:08 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		free_split(char **tab, int size)
{
	while (size-- > 0)
	{
		free(tab[size]);
		tab[size] = NULL;
	}
	free(tab);
	tab = NULL;
	return (-1);
}

int		free_z(int **tab, int size)
{
	while (size-- > 0)
	{
		free(tab[size]);
		tab[size] = NULL;
	}
	free(tab);
	tab = NULL;
	return (-1);
}

int		precision_print(int nbr)
{
	int		res;

	res = 0;
	if (nbr < 0)
	{
		res++;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		res++;
	}
	return (res);
}

void	background_color(t_img *img, int height, unsigned int color, int op)
{
	int		i;
	int		red;
	int		green;
	int		blue;

	i = 0;
	blue = color % 256;
	color = color / 256;
	green = color % 256;
	color = color / 256;
	red = color % 256;
	while (i < WIN_WIDTH * height * 4)
	{
		img->data[i] = blue;
		img->data[i + 1] = green;
		img->data[i + 2] = red;
		img->data[i + 3] = op;
		i = i + 4;
	}
}

void	move_title(t_fdf *fdf)
{
	static int	title = WIN_WIDTH;
	int			title_color;

	fdf->x_title = (title == 0) ? fdf->x_title - 1 : fdf->x_title + 1;
	if (fdf->x_title == WIN_WIDTH - (int)ft_strlen(fdf->title) * 10)
		title = 0;
	if (fdf->x_title == 0)
		title = WIN_WIDTH;
	title_color = (fdf->title_color == 0) ? rand() % 0xffffff : 0;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x_title, 5, \
					title_color, fdf->title);
}
