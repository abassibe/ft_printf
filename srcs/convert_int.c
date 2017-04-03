/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/03 19:02:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*allocate_str(t_print *lst)
{
	lst->len_str = (int)ft_strlen(lst->str_nb);
	if (lst->len_str < lst->long_opt)
		lst->len_str = lst->long_opt;
	if (lst->len_str < lst->long_preci)
		lst->len_str = lst->long_preci;
	if ((lst->long_preci >= lst->long_opt && lst->neg == 1) ||
			(lst->opt == '+') || (lst->opt == ' '))
		lst->len_str++;
	lst->str = ft_strnew(lst->len_str); //allocation
	return (lst);
}

t_print		*conv_d(t_print *lst, va_list ap)
{
	lst->i = va_arg(ap, int);
	lst->str_nb = ft_strdup(ft_itoa(lst->i));
	lst->len_str_nb = ft_strlen(lst->str_nb);
	if (lst->i < 0)
		lst->neg = 1;
	return (lst);
}

t_print		*conv_int(t_print *lst, va_list ap)
{
	if (ft_strcmp("h", lst->taille) == 0)
		lst = conv_h(lst, ap);
	else if (ft_strcmp("hh", lst->taille) == 0)
		lst = conv_hh(lst, ap);
	else if ((ft_strcmp("l", lst->taille) == 0) ||
			(ft_strcmp("ll", lst->taille) == 0))
		lst = conv_l(lst, ap);
	else if (ft_strcmp("j", lst->taille) == 0)
		lst = conv_j(lst, ap);
	else if (ft_strcmp("z", lst->taille) == 0)
		lst = conv_z(lst, ap);
	else
		lst = conv_d(lst, ap);
	lst = allocate_str(lst);
	return (lst);
}

t_print		*init_opt(t_print *lst)
{
	lst->c = 0;
	lst->s_int = 0;
	lst->str_nb = NULL;
	lst->len_str_nb = 0;
	lst->taille = NULL;
	lst->opt = 0;
	lst->long_opt = 0;
	lst->long_preci = -1;
	lst->neg = 0;
	lst->str = NULL;
	return (lst);
}
