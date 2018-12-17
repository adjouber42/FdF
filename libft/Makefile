# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjouber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:28:20 by adjouber          #+#    #+#              #
#    Updated: 2018/12/17 12:19:54 by adjouber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strncat.c \
	   ft_strncpy.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strclr.c \
	   ft_bzero.c \
	   ft_memset.c \
	   ft_memmove.c \
	   ft_memdel.c \
	   ft_memcpy.c \
	   ft_memcmp.c \
	   ft_memchr.c \
	   ft_memccpy.c \
	   ft_memalloc.c \
	   ft_strdel.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strsplit.c \
	   ft_putendl.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strtrim.c \
	   ft_strncmp.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   get_next_line.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIBFT:		your libft is ready"

%.o: %.c
	@gcc -Wall -Werror -Wextra -I includes/ -c $< -o $@

clean :
	@rm -f $(OBJS)
	@echo "LIBFT		Removing OBJ path"

fclean : clean
	@rm -f $(NAME)
	@echo "LIBFT		Removing libft.a"

re : fclean all

.PHONY: all, clean, fclean, re
