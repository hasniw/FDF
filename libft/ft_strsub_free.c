/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:00 by mnaji             #+#    #+#             */
/*   Updated: 2019/02/10 19:34:02 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char *s, int start, size_t len)
{
	char	*str;

	if (!(str = ft_strsub(s, start, len)))
		return (NULL);
	ft_strdel(&s);
	return (str);
}
