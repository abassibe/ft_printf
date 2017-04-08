/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:13:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/08 05:28:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"
#include <stdio.h>
#include <locale.h>

typedef struct			s_print
{
	int					in;
	int					neg;
	char				*conv;
	int					nbr_arg;
	const char			*fmt;
	char				*output;
	int					out_size;
	int					plus;
	int					less;
	int					diez;
	int					zero;
	int					space;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					got_opt;
	int					long_opt;
	int					long_preci;
	char				*str_nb;
	int					len_str_conv;
	int					len_str;
	char				*str;
	char				c;
	signed char			*s_str;
	signed char			s_c;
	unsigned char		*us_str;
	unsigned char		us_c;
	int					hexa;
	long int			l_hexa;
	int					octal;
	long int			l_octal;
	int					i;
	size_t				size_t_i;
	unsigned int		us_int;
	short				s_int;
	unsigned short		uss_int;
	long int			l_int;
	unsigned long		usl_int;
	unsigned long long	usll_int;
	double				d_int;
	float				f_int;
	wchar_t				*uni_str;
	wchar_t				uni_c;
	char				*address;
}						t_print;

int						ft_printf(const char *format, ...);
t_print					*init_opt(t_print *lst);
t_print					*crea_lst(const char *format);

char					*core(t_print *lst, va_list ap);
int						chk_percent(t_print *lst, char *ret, va_list ap, int *c);
t_print					*chk_conv(t_print *lst, char *corr_conv, va_list ap, int ind);

void					verif_format(t_print *lst, va_list ap, int ind);
t_print					*recup_format(t_print *lst);
t_print					*dispatch_one(t_print *lst, va_list ap, int pos);
t_print					*dispatch_two(t_print *lst, va_list ap, int pos);
t_print					*dispatch_three(t_print *lst, va_list ap, int pos);

t_print					*convert_string(t_print *lst);
t_print					*options_zero(t_print *lst, char *str, int lenght);
t_print					*options_pos(t_print *lst, char *str, int lenght);
t_print					*options_neg(t_print *lst, char *str, int lenght);

t_print					*conv_int(t_print *lst, va_list ap);
t_print					*conv_d(t_print *lst, va_list ap);
t_print					*allocate_str(t_print *lst);

t_print					*conv_h(t_print *lst, va_list ap);
t_print					*conv_hh(t_print *lst, va_list ap);
t_print					*conv_l(t_print *lst, va_list ap);
t_print					*conv_j(t_print *lst, va_list ap);
t_print					*conv_z(t_print *lst, va_list ap);

t_print					*preci_int(t_print *lst);

t_print					*field_int(t_print *lst);

t_print					*recup_format(t_print *lst);
t_print					*recup_opt(t_print *lst, int i);
t_print					*lenght_field(t_print *lst, int *i);
t_print					*recup_preci(t_print *lst, int *i);
t_print					*recup_flag(t_print *lst, int *i);

void					conv_s(t_print *lst, va_list ap);

t_print					*preci_string(t_print *lst);

void					conv_c(t_print *lst, va_list ap);

void					conv_hexa(t_print *lst, va_list ap);

void					conv_octal(t_print *lst, va_list ap);

t_print					*concaten_result(t_print *lst, int ind);

#endif
