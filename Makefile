# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/04/11 16:40:03 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PRINTFSRC =	ft_printf.c \
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
			conv_uint.c \
			conv_percent.c

LFTSRC =	ft_atoi.c \
			ft_itoa_long.c \
			ft_itoa_ulong.c \
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
			ft_memset.c \
			ft_strchr.c

OBJS1 = $(LFTSRC:.c=.o)
	OBJS2 = $(PRINTFSRC:.c=.o)
	OBJS = $(OBJS2) $(OBJS1)

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS2)) $(addprefix objs/, $(OBJS1))
		@printf "\033[0;35m> Compiling libftprintf.a\033[0m"
			@ar rc $(NAME) $(addprefix objs/, $(OBJS))
				@printf "\033[0;32m > OK\n\033[0m"

$(addprefix objs/, $(OBJS1)): $(addprefix libft/, $(LFTSRC))
		@printf "\033[0;35m.\033[0m"
			@gcc $(FLAGS) -c $(addprefix libft/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

$(addprefix objs/, $(OBJS2)): $(addprefix srcs/, $(PRINTFSRC))
		@test -d objs || mkdir objs
			@printf "\033[0;35m.\033[0m"
				@gcc $(FLAGS) -c $(addprefix srcs/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

main: a.out
		@printf "\033[0;31m- Executing a.out -\n\033[0m"
			@./a.out
				@printf "\033[0;31m-- End of a.out --\n\033[0m"

a.out: $(NAME) main.c
		@gcc -Wall -Wextra main.c -L. -lftprintf -I includes/

test: test.out
		@printf "\033[0;31m- Executing test.out -\n\033[0m"
			@./test.out $(ARGS)
				@printf "\033[0;31m-- End of test.out --\n\033[0m"

test.out: $(NAME) test.c
		@gcc -Wall -Wextra test.c -L. -lftprintf -I includes/ -o test.out

clean:
		@rm -rdf objs/

fclean: clean
		@rm -f $(NAME)

mainclean:
		@rm -f a.out

testclean:
		@rm -f test.out

cleanall: mainclean testclean fclean

re: fclean all
