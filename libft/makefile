# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/09 06:42:14 by abassibe          #+#    #+#              #
#    Updated: 2017/04/09 06:47:20 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_itoa_base.c ft_itoa_base_maj.c ft_itoa_base_maj_unsigned.c \
	  ft_itoa_base_unsigned.c ft_itoa_long.c ft_memalloc.c ft_memset.c ft_putchar.c \
	  ft_putstr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@printf "\033[0;36m> Compiling libft\033[0m"
			@ar rc $(NAME) $(OBJS)
				@printf "\033[0;32m OK\n\033[0m"

$(OBJS):
		@gcc $(FLAGS) -c $(SRC) -I ../includes/

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
