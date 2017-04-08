/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 01:09:58 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/08 01:40:41 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_c_next(t_print *lst)
{
	int		i;

	i = 0;
	if (lst->less == 1)
	{
		lst->str[i++] = lst->c;
		while (i < lst->len_str_conv)
			lst->str[i++] = ' ';
	}
	else if (lst->zero == 1)
	{
		while (i < lst->len_str_conv - 1)
			lst->str[i++] = '0';
		lst->str[i] = lst->c;
	}
	else if (lst->space == 1 || lst->diez == 1 || lst->plus == 1)
	{
		while (i < lst->len_str_conv - 1)
			lst->str[i++] = ' ';
		lst->str[i] = lst->c;
	}
	else
		lst->str[0] = lst->c;
}

void	conv_c(t_print *lst, va_list ap)
{
	lst->c = va_arg(ap, int);
	lst->len_str_conv = 1;
	if (lst->len_str_conv < lst->long_opt)
		lst->len_str_conv = lst->long_opt;
	lst->str = ft_strnew(lst->len_str_conv);
	conv_c_next(lst);
}
