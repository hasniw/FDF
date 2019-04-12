/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 13:54:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/12 16:26:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 500
# define HEIGHT 500

#include "../libft/libft.h"

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct  s_args
{
    char *file;
}               t_args;
#endif
