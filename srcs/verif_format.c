/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:05:20 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/20 14:38:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		dispatch_four(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'C')
	{
		lst->l = 1;
		conv_c(lst, ap);
	}
	else if (lst->conv[pos] == '%')
		conv_percent(lst);
	else
		lst->str = ft_strnew(0);
}

static void		dispatch_three(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'u')
	{
		conv_uint(lst, ap);
		preci_int(lst);
		field_int(lst);
	}
	else if (lst->conv[pos] == 'x')
	{
		recup_args_hexa(lst, ap, 0);
		conv_hexa_x(lst);
	}
	else if (lst->conv[pos] == 's')
	{
		conv_s(lst, ap);
		preci_string(lst);
		convert_string(lst);
	}
	else if (lst->conv[pos] == 'c')
		conv_c(lst, ap);
	else
		dispatch_four(lst, ap, pos);
}

static void		dispatch_two(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'D')
	{
		lst->l = 1;
		conv_int(lst, ap);
		preci_int(lst);
		field_int(lst);
	}
	else if (lst->conv[pos] == 'o')
		conv_octal(lst, ap);
	else if (lst->conv[pos] == 'U')
	{
		lst->l = 1;
		conv_uint(lst, ap);
		preci_int(lst);
		field_int(lst);
	}
	else if (lst->conv[pos] == 'O')
	{
		lst->l = 1;
		conv_octal(lst, ap);
	}
	else
		dispatch_three(lst, ap, pos);
}

static void		dispatch_one(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'X')
	{
		recup_args_hexa(lst, ap, 1);
		conv_hexa_x(lst);
		if (lst->str[1] == 'x')
			lst->str[1] = 'X';
	}
	else if (lst->conv[pos] == 'S')
	{
		lst->l = 1;
		conv_s(lst, ap);
		preci_string(lst);
		convert_string(lst);
	}
	else if (lst->conv[pos] == 'p')
		conv_hexa(lst, ap);
	else if (lst->conv[pos] == 'd' || lst->conv[pos] == 'i')
	{
		conv_int(lst, ap);
		preci_int(lst);
		field_int(lst);
	}
	else
		dispatch_two(lst, ap, pos);
}

void			verif_format(t_print *lst, va_list ap)
{
	int		pos;

	pos = ft_strlen(lst->conv) - 1;
	recup_format(lst);
	dispatch_one(lst, ap, pos);
	if (lst->str_nb != NULL)
	{
//		free(lst->str_nb);
		lst->str_nb = NULL;
	}
}
