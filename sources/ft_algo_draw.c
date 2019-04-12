/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:44:22 by wahasni           #+#    #+#             */
/*   Updated: 2019/02/21 19:54:14 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf/fdf.h"


void	firt(t_args args, t_line line, t_img *image)
{
	int i;
	int cumul;

	cumul = line.dx / 2;
	i = 1;
	pixel_to_img(image, line.line_x, line.line_y,
			fcolor(line.line_z, args.diff, args.modif.color));
	while (i <= line.dx)
	{
		line.line_x += line.xinc;
		cumul += line.dy;
		if (cumul >= line.dx)
		{
			cumul -= line.dx;
			line.line_y += line.yinc;
		}
		pixel_to_img(image, line.line_x, line.line_y, \
				fcolor(line.line_z, args.diff, args.modif.color));
		i++;
	}
}

void	second_part(t_args args, t_line line, t_img *image)
{
	int i;
	int cumul;

	cumul = line.dy / 2;
	i = 1;
	pixel_to_img(image, line.line_x, line.line_y,
			fcolor(line.line_z, args.diff, args.modif.color));
	while (i <= line.dy)
	{
		line.line_y += line.yinc;
		cumul += line.dx;
		if (cumul >= line.dy)
		{
			cumul -= line.dy;
			line.line_x += line.xinc;
		}
		pixel_to_img(image, line.line_x, line.line_y, \
				fcolor(line.line_z, args.diff, args.modif.color));
		i++;
	}
}

int		print_line(t_args args, t_line line, t_img *image)
{
	if (line.dx > line.dy)
		first_part(args, line, image);
	else
		second_part(args, line, image);
	return (1);
}
