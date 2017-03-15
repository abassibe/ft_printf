/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:13:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/15 05:47:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

# define FMT g_print.input
# define OUT g_print.output
# define OUT_S g_print.out_size
# define IND g_print.index
# define ARG g_print.nbr_arg

typedef struct		s_print
{
	int					index;
	int					nbr_arg;
	char				*input;
	char				**output;
	int					out_size;
	char				*str;
	char				c;
	signed char			*s_str;
	signed char			s_c;
	unsigned char		*us_str;
	unsigned char		us_c;
	int					i;
	unsigned int		us_int;
	short				s_int;
	unsigned short		uss_int;
	long				l_int;
	unsigned long		usl_int;
	long long			ll_int;
	unsigned long long	usll_int;
	double				d_int;
	float				f_int;
	wchar_t				*uni_str;
	wchar_t				uni_c;
	char				*address;
}						t_print;

t_print					g_print;

int						ft_printf(const char *format, ...);

char					*core(const char *format, va_list ap);

int						chk_error(const char *format, va_list aq);

#endif
