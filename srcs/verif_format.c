/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:05:20 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/09 06:06:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*dispatch_three(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'U')
	{
	}
	else if (lst->conv[pos] == 'x')
	{
		recup_args_hexa(lst, ap, 0);
		conv_hexa_x(lst);
	}
	else if (lst->conv[pos] == 'X')
	{
		recup_args_hexa(lst, ap, 1);
		conv_hexa_x(lst);
		if (lst->str[1] == 'x')
			lst->str[1] = 'X';
	}
	else if (lst->conv[pos] == 'c')
		conv_c(lst, ap);
	else if (lst->conv[pos] == 'C')
	{
		lst->l = 1;
		conv_c(lst, ap);
	}
	return (lst);
}

t_print		*dispatch_two(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'D')
	{
		lst->l = 1;
		lst = conv_int(lst, ap);
		lst = preci_int(lst);
		lst = field_int(lst);
	}
	else if (lst->conv[pos] == 'o')
		conv_octal(lst, ap);
	else if (lst->conv[pos] == 'O')
	{
		lst->l = 1;
		conv_octal(lst, ap);
	}
	else if (lst->conv[pos] == 'u')
	{
	}
	else
		dispatch_three(lst, ap, pos);
	return (lst);
}

t_print		*dispatch_one(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 's')
	{
		conv_s(lst, ap);
		lst = preci_string(lst);
		lst = convert_string(lst);
	}
	else if (lst->conv[pos] == 'S')
	{
		lst->l = 1;
		conv_s(lst, ap);
		lst = preci_string(lst);
		lst = convert_string(lst);
	}
	else if (lst->conv[pos] == 'p')
		conv_hexa(lst, ap);
	else if (lst->conv[pos] == 'd' || lst->conv[pos] == 'i')
	{
		lst = conv_int(lst, ap);
		lst = preci_int(lst);
		lst = field_int(lst);
	}
	else
		dispatch_two(lst, ap, pos);
	return (lst);
}

void		verif_format(t_print *lst, va_list ap, int ind)
{
	int		pos;

	lst->conv = ft_strsub(lst->fmt, ind, (lst->in - ind) + 1);
	lst = recup_format(lst);
	pos = lst->in - ind;
	lst->conv = ft_strsub(lst->fmt, ind, (lst->in - ind) + 1);
	dispatch_one(lst, ap, pos);
	lst = concaten_result(lst, ind);
}
