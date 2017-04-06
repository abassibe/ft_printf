/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/06 06:54:07 by abassibe         ###   ########.fr       */
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
	lst->str = ft_strnew(lst->len_str); //allocation
	return (lst);
}

t_print		*conv_d(t_print *lst, va_list ap)
{
	unsigned long long	nb;

	lst->i = va_arg(ap, int);
	nb = lst->i;
	if (lst->i < 0)
	{
		lst->neg = 1;
		nb = (long long)(lst->i) * -1;
	}
	lst->str_nb = ft_strdup(ft_itoa_long(nb));
	lst->len_str_conv = ft_strlen(lst->str_nb);
	return (lst);
}

t_print		*conv_int(t_print *lst, va_list ap)
{
	if (lst->h == 1)
		lst = conv_h(lst, ap);
	else if (lst->hh == 1)
		lst = conv_hh(lst, ap);
	else if (lst->l == 1 || lst->ll == 1)
		lst = conv_l(lst, ap);
	else if (lst->j == 1)
		lst = conv_j(lst, ap);
	else if (lst->z == 1)
		lst = conv_z(lst, ap);
	else
		lst = conv_d(lst, ap);
	lst = allocate_str(lst);
	return (lst);
}
