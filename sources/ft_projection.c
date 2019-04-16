/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:25:20 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/16 23:32:17 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_altitude_i(int *x, int *y, int z, t_env env)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (-z * env.range) + (previous_x + previous_y) * sin(0.523599);
}

void	ft_altitude_p(int *x, int *y, int z, t_env env)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y);
	*y = (-z * env.range) + (previous_x + previous_y);
}

/// DEMANDER DES EXPLICATIONS A MICKA