/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 13:54:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/20 02:55:08 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# define WIDTH 500
# define HEIGHT 500
# define USAGE_ERROR -1
# define MALLOC_ERROR -2
# define READ_ERROR -3
# define MAP_ERROR -4

#include "../libft/libft.h"
#include <fcntl.h>
#include <string.h>
#include <string.h>
#include "mlx.h"
#include <stdio.h>

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
	void		*mlx_ptr;
    void		*win_ptr;
}				t_args;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			line_x;
	int			line_y;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
}				t_line;

typedef struct s_image
{
	void		*ptr;
	void		*img;
	int			bpp;
	int			endian;
	int			line_size;
	int			width;
	int			height;
}				t_image;

t_point	*ft_parsing(t_args *args);
int     create_window(t_args *args);
int     create_image(t_image *image, t_args *args);
int     deal_mouse(int mouse, int x, int y, t_args *args);
int     deal_key(int key, t_args *args);
void    map_color(void *mlx_ptr, void *win_ptr, int color);
int     ft_print_error(int error);
void    create_line(t_args *args, t_point *position, t_image *image);
void	ft_altitude_i(t_point i, t_point f, t_line *line, t_args args);
void	ft_altitude_p(t_point i, t_point f, t_line *line, t_args args);
void	put_line(t_line *line, t_args *args);

#endif
