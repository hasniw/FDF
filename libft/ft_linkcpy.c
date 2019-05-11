/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:37:32 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/05 00:02:50 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_linkcpy(t_list *link)
{
	t_list	*new;

	if (!(new = ft_lstnew(link->content, link->content_size)))
		return (NULL);
	(*new).next = (*link).next;
	return (new);
}
