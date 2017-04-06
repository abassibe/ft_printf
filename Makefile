# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/04/06 01:58:26 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
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
		ft_atoi.c \
		ft_itoa_long.c \
		ft_putstr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_memset.c \

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

SRCSFULL = $(addprefix $(SRCPATH), $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) *.o
	@ranlib $(NAME)

$(OBJS): $(SRCSFULL)
	@gcc $(FLAGS) -c $(SRCSFULL) -I ./includes/

.PHONY: all clean fclean re

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
