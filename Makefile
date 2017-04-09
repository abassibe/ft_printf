# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/04/09 06:18:04 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		core.c \
		verif_format.c \
		recup_format.c \
		convert_int.c \
		convert_int_next.c \
		preci_int.c \
		field_int.c \
		field_int_next.c \
		field_string.c \
		conv_string.c \
		preci_string.c \
		conv_char.c \
		conv_hexa.c \
		conv_octal.c \
		conv_hexa_x.c \
		recup_args_hexa.c \
		concaten_result.c \
		ft_atoi.c \
		ft_itoa_long.c \
		ft_itoa_base.c \
		ft_itoa_base_maj.c \
		ft_itoa_base_unsigned.c \
		ft_itoa_base_maj_unsigned.c \
		ft_putstr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_memset.c

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
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
