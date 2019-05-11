/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:24:40 by mnaji             #+#    #+#             */
/*   Updated: 2018/11/16 22:07:09 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	end;
	unsigned int	i;

	end = (unsigned int)len + start;
	i = 0;
	if (!s || (start > ft_strlen(s)) || ((end > (unsigned int)ft_strlen(s))
				|| !(str = (char*)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
