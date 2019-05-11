/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:34:57 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:35:10 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_first(t_list *lst)
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	if (!(new = ft_lstnew(NULL, 0)))
		return (lst);
	new = (*lst).next;
	free(lst);
	lst = NULL;
	return (new);
}
