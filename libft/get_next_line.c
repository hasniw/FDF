/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:41:22 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/30 13:38:49 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*new_line(const int fd, char *buff, t_gnl **flst)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->buff = ft_strdup(buff);
	if (!(new->buff))
		return (NULL);
	new->next = *flst;
	*flst = new;
	return (new);
}

static t_gnl		*check_fd(const int fd, t_gnl *flst)
{
	while (flst)
	{
		if (flst->fd == fd)
			return (flst);
		flst = flst->next;
	}
	return (NULL);
}

static int			check_elem(int const fd, char *buff, t_gnl **flst)
{
	t_gnl	*elem;
	char	*tmp;

	elem = check_fd(fd, *flst);
	if (!elem)
	{
		if (!(elem = new_line(fd, buff, flst)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(elem->buff, buff)))
			return (-1);
		free(elem->buff);
		elem->buff = tmp;
	}
	if (ft_strchr(elem->buff, '\n') != 0)
		return (1);
	return (0);
}

static char			*line_tracker(int const fd, t_gnl *flst, int i)
{
	t_gnl	*elem;
	char	*tmp;
	char	*res;

	res = NULL;
	if (!(elem = check_fd(fd, flst)) || !elem->buff)
		return (NULL);
	if ((ft_strchr(elem->buff, '\n') != 0))
	{
		while (elem->buff[i] != '\n' && elem->buff[i] != '\0')
			i++;
		res = ft_strsub(elem->buff, 0, i);
		tmp = ft_strdup(&elem->buff[i + 1]);
		free(elem->buff);
		elem->buff = tmp;
	}
	else
	{
		if (ft_strlen(elem->buff) != 0 && !(res = ft_strdup(elem->buff)))
			return (NULL);
		free(elem->buff);
		elem->buff = NULL;
	}
	return (res);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*flst;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				end;
	int				i;

	i = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if ((end = check_elem(fd, buff, &flst)) == 1)
		{
			*line = line_tracker(fd, flst, i);
			return (1);
		}
		if (end == -1)
			return (-1);
	}
	if ((*line = line_tracker(fd, flst, i)) != NULL)
		return (1);
	return (0);
}
