/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:20 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/23 14:45:21 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_altitude_i(t_point i, t_point f, t_line *line, t_args args)
{
    static int g = 0;
    // printf("i.x : %d, i.y : %d\n", i.x, i.y);
    // printf("f.x : %d, f.y : %d\n", f.x, f.y);
	line->x1 = (i.x - i.y) * cos(0.523599) + 10;// + (WIDTH / 6);
    line->y1 = -i.z + (i.x + i.y) * sin(0.523599) + 10;// + (HEIGHT / 6);
    line->x2 = (f.x - f.y) * cos(0.523599) + 10;// + (WIDTH / 6);
    line->y2 = -f.z + (f.x + f.y) * sin(0.523599) + 10;// + (HEIGHT / 6);
    line->line_x = line->x1 + g;
    line->line_y = line->y1 + g;
    line->dx = line->x2 - line->x1;
    line->dy = line->y2 - line->y1;
    g += 15;
    // printf("line->x1 : %d\n", line->x1);
    // printf("line->x2 : %d\n", line->x2);
}

void	ft_altitude_p(t_point i, t_point f, t_line *line, t_args args)
{
	line->x1 = i.x - i.z * 2;
    line->y1 = i.y - i.z * 5;
    line->x2 = f.x - f.z * 2;
    line->y2 = f.y - f.z * 5;
    line->line_x = i.x - i.z * 2;
    line->line_y = i.y - i.z * 5;
    line->dx = (f.x - f.z * 2) - (i.x - i.z * 2);
    line->dy = (f.y - f.z * 5) - (i.y - i.z * 5);
}

/// DEMANDER DES EXPLICATIONS A MICKA