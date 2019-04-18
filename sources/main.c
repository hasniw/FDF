/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:16:38 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/18 23:54:53 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	int fd;
	t_point *position;
	t_image *image;
	t_args args;

	image = ft_memalloc(sizeof(image));
	args.file = av[1];
	if (ac != 2)
		return (ft_print_error(USAGE_ERROR));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_print_error(MAP_ERROR));
	position = ft_parsing(&args);
	if (create_window(&args))
		return (-1);
	if (create_image(image, &args))
		return (-1);
	printf("10\n");
	// n = ft_display_pixel(&args, position);
	mlx_get_color_value(args.mlx_ptr, 0xffffff);
	mlx_put_image_to_window(args.mlx_ptr, args.win_ptr, image->img, 500, 500);
	printf("%d\n", args.nb_point);
	mlx_mouse_hook(args.win_ptr, deal_mouse, &args);
	mlx_key_hook(args.win_ptr, deal_key, &args);
	mlx_loop(args.mlx_ptr);
	return (0);
}