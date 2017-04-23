/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:27:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/23 05:45:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print			*crea_lst(const char *format)
{
	t_print		*new;

	new = (t_print *)malloc(sizeof(t_print));
	new->fmt = ft_strdup((char *)format);
	return (new);
}

static void		init_opt_next(t_print *lst)
{
	lst->long_preci = -1;
	lst->neg = 0;
	lst->str = NULL;
	lst->len_str = 0;
	lst->conv = NULL;
	lst->tab = NULL;
	lst->s_str = NULL;
	lst->s_c = 0;
	lst->us_str = NULL;
	lst->us_c = 0;
	lst->l_hexa = 0;
	lst->i = 0;
	lst->usl_int = 0;
	lst->d_int = 0;
	lst->f_int = 0;
	lst->uni_str = NULL;
	lst->uni_c = 0;
	lst->conv_c = 0;
	lst->bool_star = 0;
	lst->apostrophe = 0;

}

void			init_opt(t_print *lst)
{
	lst->h = 0;
	lst->hh = 0;
	lst->l = 0;
	lst->ll = 0;
	lst->j = 0;
	lst->z = 0;
	lst->plus = 0;
	lst->less = 0;
	lst->diez = 0;
	lst->zero = 0;
	lst->space = 0;
	lst->got_opt = 0;
	lst->long_opt = 0;
	lst->c = 0;
	lst->s_int = 0;
	lst->uss_int = 0;
	lst->us_int = 0;
	lst->us_c = 0;
	lst->usll_int = 0;
	lst->l_int = 0;
	lst->size_t_i = 0;
	lst->str_nb = NULL;
	lst->len_str_conv = 0;
	init_opt_next(lst);
}

int				ft_printf(const char *format, ...)
{
	t_print		*lst;
	va_list		ap;

	va_start(ap, format);
	lst = crea_lst(format);
	init_opt(lst);
	lst->c_zero = 0;
	core(lst, ap);
	va_end(ap);
	ft_putstr(lst->fmt);
//	free(lst->fmt);
//	free(lst);
	return ((int)ft_strlen(lst->fmt) + lst->c_zero);
}
