/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_nfirst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:33:24 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:34:32 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_nfirst(t_list *lst, int i)
{
	if (lst == NULL)
		return (NULL);
	while (i > 0)
	{
		lst = ft_lstdel_first(lst);
		i--;
	}
	return (lst);
}
