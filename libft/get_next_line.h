/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:37:21 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/30 13:38:11 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 1

typedef struct			s_gnl
{
	char				*buff;
	int					fd;
	struct s_fd			*next;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
