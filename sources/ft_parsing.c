/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 22:04:49 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/13 22:29:43 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_point(t_args *args)
{
	int		fd;
	int		i;
	int		nb;
	char	*line;
	char	**tab;

	nb = 0;
	if ((fd = open(args->file, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, line) == 1)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
		{
			if (!ft_isnumber(tab[i]))
				return (-1);
			ft_strdel(tab[i++]);
		}
		/*free(tab);*/
		ft_strdel(line);
		nb += i;
	}
	return (nb);
}

t_point	ft_parsing(t_args *args)
{
	int		fd;
	char	*line;
	int		nbline;

	nbline = 0;
	args->nb_point = count_point(args);
	/*if (!())*/
	if ((fd = open(args->file, O_RDONLY)) < 0)
		return (*args->all_point);
	while (get_next_line(fd, line) == 1)
	{
		ft_assign(line, args, nbline);
		nbline++;
		ft_strdel(line);
	}
	return (*args->all_point);
}

int main(int ac, char **av)
{
	
}