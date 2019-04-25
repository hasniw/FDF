/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:45:58 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/25 21:19:02 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     ft_print_error(int error)
{
    if (error == USAGE_ERROR)
        ft_putstr_fd("Usage : ./fdf <map.fdf>\n", 2);
    if (error == MALLOC_ERROR)
        ft_putstr_fd("MALLOC ERROR", 2);
    if (error == READ_ERROR)
        ft_putstr_fd("READ ERROR", 2);
    if (error == MAP_ERROR)
        ft_putstr_fd("Enter a valid file", 2);
    return (error);
}