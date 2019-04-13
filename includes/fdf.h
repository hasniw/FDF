/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 13:54:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/13 17:42:28 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define WIDTH 500
#define HEIGHT 500

#include "../libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_args
{
	char		*file;
	int			nb_point;
	t_point		*all_point;
}				t_args;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			line_x;
	int			line_y;
	int			line_z;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
}				t_line;

#endif
