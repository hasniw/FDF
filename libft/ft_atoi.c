/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 06:05:05 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/17 06:23:03 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]))
			i++;
		else
			return (0);
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[sign] == '-')
		result *= -1;
	return (result);
}
