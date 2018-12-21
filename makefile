# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjouber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 12:07:03 by adjouber          #+#    #+#              #
#    Updated: 2018/12/21 18:20:41 by adjouber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = src/main.c \
	   src/read.c \
	   src/fdf.c \
	   src/color.c \
	   src/draw.c \
	   src/display.c \
	   src/keyboard.c

OBJS = $(SRCS:.c=.o)

FLAG = -g3 -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS)
	@gcc -Wall -Werror -Wextra $(FLAG) -o $(NAME) $(OBJS) -I libft/includes -I /usr/local/include -I include -L libft/ -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
	@echo "FDF:		FDF READY"

%.o : %.c
	@make -C libft/
	@gcc -Wall -Werror -Wextra $(FLAG) -I libft/includes -I /usr/local/include -I include -c $< -o $@

clean :
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "FDF:		Removing OBJ path"

fclean : clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "FDF:		Removing FDF executable"

re : fclean all

.PHONY: all, clean, fclean, re
