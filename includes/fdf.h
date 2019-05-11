/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:48:00 by mnaji             #+#    #+#             */
/*   Updated: 2019/05/08 16:27:55 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH	1280
# define WIN_HEIGHT 880
# define IMG_WIDTH	1280
# define IMG_HEIGHT	720

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
	int		op;
}				t_color;

typedef struct	s_draw
{
	int		xt;
	int		yt;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_draw;

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		size_line;
	int		endian;
	int		bpp;
	t_color	color;
}				t_img;

typedef struct	s_map
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		initialise_map;
	int		**z;
	double	mult_z;
	double	projection;
	double	zoom;
	double	anim_zoom;
	double	mult_zoom;
	int		precision_print;
	t_img	img;
}				t_map;

typedef struct	s_usage
{
	t_img			img;
	int				color_map;
	unsigned int	backg_color;
	int				op_color;
}				t_usage;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*title;
	int		x_title;
	int		title_color;
	t_usage	usage;
	t_map	map;
}				t_fdf;

int				parsing(char *file, t_map *map);
int				free_split(char **tab, int size);
int				free_z(int **tab, int size);
int				deal_hook(t_fdf *fdf);
int				deal_mouse(int mouse, int x, int y, t_fdf *fdf);
int				deal_key(int key, t_fdf *fdf);
void			initialise_fdf(t_fdf *fdf);
void			background_color(t_img *img, int height, \
								unsigned int color, int op);
void			header(t_usage *usage, t_fdf *fdf);
int				precision_print(int nbr);
void			move_title(t_fdf *fdf);

#endif
