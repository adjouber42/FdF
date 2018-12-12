# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjouber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 12:07:03 by adjouber          #+#    #+#              #
#    Updated: 2018/12/12 14:05:30 by adjouber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c \
	   read.c \
	   fdf.c \
	   draw.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS) -I libft/includes -I /usr/local/include -L libft/ -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/includes -I /usr/local/include -c $< -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
