/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 22:04:49 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/14 17:12:57 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

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
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
		{
			if (!ft_isnumber(tab[i]))
				return (-1);
			ft_strdel(&tab[i++]);
		}
		free(tab);
		ft_strdel(&line);
		nb += i;
	}
	return (nb);
}

int		ft_assign(char *line, t_args *args, int nbline)
{
	int			i;
	static int	j = 0;
	char		**tab;

    i = 0;
    tab = ft_strsplit(line, ' ');
    while (tab[i])
    {
        args->all_point[j].x = i;
        args->all_point[j].y = nbline;
        args->all_point[j].z = ft_atoi(tab[i]);
        i++;
        j++;
    }
    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
    return (1);
}

t_point	*ft_parsing(t_args *args)
{
	int		fd;
	char	*line;
	int		nbline;

	printf("0\n");
	nbline = 0;
	args->nb_point = count_point(args);
	if (!(args->all_point = malloc(sizeof(t_point *) * args->nb_point)))
		return (args->all_point); //Erreur malloc
	if ((fd = open(args->file, O_RDONLY)) < 0)
		return (args->all_point); //Erreur fd
	while (get_next_line(fd, &line) == 1)
	{
		ft_assign(line, args, nbline);
		nbline++;
		ft_strdel(&line);
	}
	printf("4\n");
	return (args->all_point);
}

int main(int ac, char **av)
{
	t_args args;
	t_point *position;
	// int i = 0;

	(void) ac;
	printf("-2\n");
	args.file = av[1];
	printf("-1\n");
	position = ft_parsing(&args);
	printf("%d\n", args.nb_point);

	return (0);
}