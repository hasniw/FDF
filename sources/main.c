/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:16:38 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/12 16:27:09 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int fd;
	t_point position;
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
	position = ft_parsing(args);