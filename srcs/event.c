/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 23:01:06 by najimehdi         #+#    #+#             */
/*   Updated: 2019/05/08 15:13:40 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	random_color(t_color *color)
{
	color->red = (rand() % 127);
	color->green = (rand() % 127);
	color->blue = (rand() % 127);
}

static void	deal_key2(int key, t_fdf *fdf)
{
	if ((key == 24 || key == 69) && (fdf->map.mult_z < 100))
	{
		fdf->map.mult_z += 0.5;
		fdf->map.mult_zoom = fdf->map.mult_z / fdf->map.zoom;
	}
	else if ((key == 27 || key == 78) && (fdf->map.mult_z > -100))
	{
		fdf->map.mult_zoom = fdf->map.mult_z / fdf->map.zoom;
		fdf->map.mult_z -= 0.5;
	}
	else if (key == 36)
		fdf->map.projection = (fdf->map.projection == 0.25) ? 0.05 : 0.25;
}

static void	deal_mouse2(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 1 && x > 690 && x < 700 && y > 100 && y < 135)
		fdf->map.y += 10;
	else if (mouse == 1 && x > 668 && x < 692 && y > 88 && y < 105)
		fdf->map.x -= 10;
	else if (mouse == 1 && x > 700 && x < 724 && y > 88 && y < 105)
		fdf->map.x += 10;
	else if (mouse == 1 && x > 940 && x < 1060 && y > 45 && y < 70)
	{
		free_z(fdf->map.z, fdf->map.height);
		exit(0);
	}
	else if (mouse == 1 && x > 940 && x < 1065 && y > 70 && y < 97)
		initialise_fdf(fdf);
	else if (mouse == 1 && x > 940 && x < 1070 && y > 108 && y < 125)
		deal_key2(24, fdf);
	else if (mouse == 1 && x > 940 && x < 1075 && y > 125 && y < 150)
		deal_key2(27, fdf);
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 42 && y <= 67)
		fdf->usage.backg_color = 0xaa0000;
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 72 && y <= 97)
		fdf->usage.backg_color = 0x00aa00;
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 102 && y <= 127)
		fdf->usage.backg_color = 0x0000aa;
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 132 && y <= 157)
		fdf->usage.backg_color = 0x555555;
}

int			deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 4 || (mouse == 1 && x > 150 && x < 340 && y > 108 && y < 125))
	{
		fdf->map.mult_z += fdf->map.mult_zoom * fdf->map.anim_zoom / 20;
		fdf->map.zoom += fdf->map.anim_zoom / 20;
	}
	else if (((mouse == 5 || (mouse == 1 && x > 150 && x < 362 && y > 125 \
	&& y < 150)) && fabs(fdf->map.mult_z) - fabs(fdf->map.mult_zoom) >= 0 \
	&& fdf->map.zoom > 0))
	{
		fdf->map.zoom -= fdf->map.anim_zoom / 35;
		fdf->map.mult_z -= fdf->map.mult_zoom * fdf->map.anim_zoom / 35;
	}
	else if (mouse == 1 && x < fdf->x_title + \
	(int)(ft_strlen(fdf->title) * 10) && x > fdf->x_title && y < 40 && y > 5)
		fdf->title_color = (fdf->title_color == 0) ? 1 : 0;
	else if (mouse == 1 && x > 150 && x < 340 && y > 45 && y < 70)
		random_color(&fdf->map.img.color);
	else if (mouse == 1 && x > 150 && x < 340 && y > 70 && y < 100)
		fdf->map.projection = (fdf->map.projection == 0.25) ? 0.05 : 0.25;
	else if (mouse == 1 && x > 690 && x < 700 && y > 70 && y < 97)
		fdf->map.y -= 10;
	else
		deal_mouse2(mouse, x, y, fdf);
	return (0);
}

int			deal_key(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		free_z(fdf->map.z, fdf->map.height);
		exit(0);
	}
	else if (key == 51)
		initialise_fdf(fdf);
	else if (key == 49)
		random_color(&fdf->map.img.color);
	else if (key == 126)
		fdf->map.y -= 10;
	else if (key == 125)
		fdf->map.y += 10;
	else if (key == 123)
		fdf->map.x -= 10;
	else if (key == 124)
		fdf->map.x += 10;
	else
		deal_key2(key, fdf);
	return (0);
}
