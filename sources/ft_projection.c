/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:20 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/25 21:51:44 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_altitude_i(t_point i, t_point f, t_line *line, t_args args)
{
    printf("Projection Isometrique\n");
	line->x1 = (i.x - i.y) * cos(0.523599);
    line->y1 = -i.z + (i.x + i.y) * sin(0.523599);
    line->x2 = (f.x - f.y) * cos(0.523599);
    line->y2 = -f.z + (f.x + f.y) * sin(0.523599);
    line->line_x = line->x1 + 200;
    line->line_y = line->y1 + 200;
    line->dx = line->x2 - line->x1;
    line->dy = line->y2 - line->y1;
}

void	ft_altitude_p(t_point i, t_point f, t_line *line, t_args args)
{
    printf("Projection Parallele\n");
	line->x1 = i.x - i.z * 2 + 500;
    line->y1 = i.y - i.z * 5 + 500;
    line->x2 = f.x - f.z * 2 - 500;
    line->y2 = f.y - f.z * 5 - 500;
    line->line_x = i.x - i.z * 2 + 200;
    line->line_y = i.y - i.z * 5 + 200;
    line->dx = (f.x - f.z * 2) - (i.x - i.z * 2);
    line->dy = (f.y - f.z * 5) - (i.y - i.z * 5);
}

/// DEMANDER DES EXPLICATIONS A MICKA