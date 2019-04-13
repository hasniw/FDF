/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 22:04:49 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/13 17:41:43 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     count_point(t_args *args)
{

}

t_point ft_parsing(t_args *args)
{
    int     fd;
    char    *line;
    int     nbline;

    nbline = 0;
    if ((fd = open(args->file, O_RDONLY)) == -1)
        return (erreur); // Retirer du main
    args->nb_point = count_point(args);
    //if (!())
    while (get_next_line(fd, line) == 1)
    {
        ft_assign(line, args, nbline);
        nbline++;
    }
    return (all_point);
}