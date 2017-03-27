/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:13:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/19 05:32:53 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <locale.h>

typedef struct		s_print
{
	int					in;
	char				*conv;
	int					nbr_arg;
	const char			*fmt;
	char				*output;
	int					out_size;
	char				opt;
	int					got_opt;
	int					long_opt;
	int					long_preci;
	char				*taille;
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

int						ft_printf(const char *format, ...);
t_print					*crea_lst(const char *format);

char					*core(t_print *lst, va_list ap);
int						chk_percent(t_print *lst, char *ret, va_list ap, int *c);
t_print					*chk_conv(t_print *lst, char *corr_conv, va_list ap, int ind);

char					*verif_format(t_print *lst, va_list ap, int ind);
t_print					*recup_format(t_print *lst);
t_print					*dispatch_one(t_print *lst, va_list ap, int pos);
t_print					*dispatch_two(t_print *lst, va_list ap, int pos);
t_print					*dispatch_three(t_print *lst, va_list ap, int pos);

t_print					*convert_string(t_print *lst);
t_print					*options_zero(t_print *lst, char *str, int lenght);
t_print					*options_pos(t_print *lst, char *str, int lenght);
t_print					*options_neg(t_print *lst, char *str, int lenght);

t_print					*convert_int(t_print *lst);
t_print					*options_neg_i(t_print *lst, char *str, char *nb, int lenght);
t_print					*options_pos_i(t_print *lst, char *str, char *nb, int lenght);
t_print					*options_diez_i(t_print *lst, char *str, char *nb, int lenght);
t_print					*options_zero_i(t_print *lst, char *str, char *nb, int lenght);
t_print					*options_sp_i(t_print *lst, char *str, char *nb, int lenght);

t_print					*recup_format(t_print *lst);
t_print					*recup_opt(t_print *lst, int *i);
t_print					*recup_preci(t_print *lst, int i);
t_print					*recup_flag(t_print *lst, int *i);

t_print					*preci_string(t_print *lst);

t_print					*preci_int(t_print *lst);
t_print					*preci_int_next(t_print *lst, char *nb, int lenght);
t_print					*preci_int_neg(t_print *lst, char *str, char *nb, int lenght);
t_print					*preci_int_noopt(t_print *lst, char *str, char *nb, int lenght);

t_print					*height_string(t_print *lst, int pos);

t_print					*height_int(t_print *lst, int pos);

t_print					*concaten_result(t_print *lst, int ind);

#endif
