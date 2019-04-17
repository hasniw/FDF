/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:16:38 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/17 19:40:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	int fd;
	t_point *position;
	t_image *image;
	t_args args;

	args.file = av[1];
	if (ac != 2)
	{
		ft_putendl("usage : ./fdf <maps>");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("enter a valid file");
		return (0);
	}
	position = ft_parsing(&args);
	if (create_window(&args))
		return (-1);
	if (create_image(image, &args))
		return (-1);
	printf("10\n");
	// n = ft_display_pixel(&args, position);
	// mlx_put_image_to_window(args.mlx_ptr, args.win_ptr, image->img, 500, 500);
	printf("%d\n", args.nb_point);
	mlx_loop(args.mlx_ptr);
	return (0);
}