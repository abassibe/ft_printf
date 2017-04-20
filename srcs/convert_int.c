/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/20 19:35:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	allocate_str(t_print *lst)
{
	lst->len_str = (int)ft_strlen(lst->str_nb);
	if (lst->len_str < lst->long_opt)
		lst->len_str = lst->long_opt;
	if (lst->len_str < lst->long_preci)
		lst->len_str = lst->long_preci;
	lst->str = ft_strnew(lst->len_str + 1);
}

void	conv_d(t_print *lst, va_list ap)
{
	unsigned long long	nb;

	lst->i = va_arg(ap, int);
	nb = lst->i;
	if (lst->i < 0)
	{
		lst->neg = 1;
		nb = (long long)(lst->i) * -1;
	}
	lst->str_nb = ft_itoa_long(nb);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

void	conv_int(t_print *lst, va_list ap)
{
	if (lst->z == 1)
		conv_z(lst, ap);
	else if (lst->j == 1)
		conv_j(lst, ap);
	else if (lst->l == 1 || lst->ll == 1)
		conv_l(lst, ap);
	else if (lst->hh == 1)
		conv_hh(lst, ap);
	else if (lst->h == 1)
		conv_h(lst, ap);
	else
		conv_d(lst, ap);
	allocate_str(lst);
}
