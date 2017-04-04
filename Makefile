# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/04/04 17:11:30 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		main2.c \
		verif_format.c \
		recup_format.c \
		convert_int.c \
		convert_int_next.c \
		preci_int.c \
		field_int.c \
		convert_s.c \
		core.c \
		preci_string.c \
		height_string.c \
		concaten_result.c \

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(addprefix $(SRCPATH), $(SRCS)) \
		-I includes/ft_printf.h
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all

