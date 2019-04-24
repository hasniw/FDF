# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wahasni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/30 14:27:51 by wahasni           #+#    #+#              #
#    Updated: 2019/02/21 21:15:58 by wahasni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = .c\

OBJS = .o\

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang $(FLAGS) -I libft -c $(SRCS) -g
	@clang $(FLAGS) -o $(NAME) $(OBJS) -I libft/ -L libft/ -lft -g -g3 -fsanitize=address 

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

lib:
	@make -C libft/ fclean && make -C libft/

.PHONY: all, ran, create, clean, fclean, re
