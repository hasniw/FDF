/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:32:42 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:33:03 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_last(t_list *lst)
{
	t_list	*first;
	t_list	*before;

	first = lst;
	if (lst == NULL)
		return (NULL);
	if ((*lst).next == NULL)
		return (ft_lstdel_first(lst));
	while ((*lst).next != NULL)
	{
		before = lst;
		lst = (*lst).next;
	}
	(*before).next = NULL;
	ft_lstdel_first(lst);
	return (first);
}
