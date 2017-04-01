/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:05:20 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 20:45:53 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*dispatch_three(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'U')
	{
		lst->usl_int = va_arg(ap, unsigned long int);
//		lst = convert_uslint(lst);
	}
	else if (lst->conv[pos] == 'x')
	{
		lst->hexa = va_arg(ap, int);
//		lst = convert_hexa(lst);
	}
	else if (lst->conv[pos] == 'X')
	{
		lst->l_hexa = va_arg(ap, long int);
//		lst = convert_lhexa(lst);
	}
	else if (lst->conv[pos] == 'c')
	{
		lst->c = va_arg(ap, int);
//		lst = convert_char(lst);
	}
	else if (lst->conv[pos] == 'C')
	{
		lst->uni_c = va_arg(ap, wchar_t);
//		lst = convert_unic(lst);
	}
	return (lst);
}

t_print		*dispatch_two(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 'D')
	{
		lst->l_int = va_arg(ap, long int);
//		lst = convert_lint(lst);
	}
	else if (lst->conv[pos] == 'o')
	{
		lst->octal = va_arg(ap, int);
//		lst = convert_octal(lst);
	}
	else if (lst->conv[pos] == 'O')
	{
		lst->l_octal = va_arg(ap, long int);
//		lst = convert_loctal(lst);
	}
	else if (lst->conv[pos] == 'u')
	{
		lst->us_int = va_arg(ap, unsigned int);
//		lst = convert_usint(lst);
	}
	else
		dispatch_three(lst, ap, pos);
	return (lst);
}

t_print		*dispatch_one(t_print *lst, va_list ap, int pos)
{
	if (lst->conv[pos] == 's')
	{
		lst->str = va_arg(ap, char *);
		lst = preci_string(lst);
		lst = convert_string(lst);
//		lst = height_string(lst, pos);
	}
	else if (lst->conv[pos] == 'S')
	{
		lst->uni_str = va_arg(ap, wchar_t *);
//		lst = convert_lstring(lst);
	}
	else if (lst->conv[pos] == 'p')
	{
		lst->address = va_arg(ap, char *);
//		lst = convert_address(lst);
	}
	else if (lst->conv[pos] == 'd' || lst->conv[pos] == 'i')
	{
//		lst->i = va_arg(ap, int);
		lst = height_int(lst, ap, pos);
		lst = i_is_neg(lst);
		if (ft_strcmp("l", lst->taille) == 0)
			lst = convert_int_l(lst);
		else
			lst = convert_int(lst);
		if (ft_strcmp("l", lst->taille) == 0)
			lst = preci_l_int(lst);
		else
			lst = preci_int(lst);
		if (ft_strcmp("l", lst->taille) == 0)
			lst = l_zero(lst);
		else
			lst = i_zero(lst);
	}
	else
		dispatch_two(lst, ap, pos);
	return (lst);
}

t_print		*i_is_neg(t_print *lst)
{
	if (lst->i < 0 || lst->l_int < 0)
	{
		lst->i *= -1;
		lst->neg = 1;
		return (lst);
	}
	return (lst);
}

char		*verif_format(t_print *lst, va_list ap, int ind)
{
	int		pos;

	lst->neg = 0;
	lst = i_is_neg(lst);
	lst->conv = ft_strsub(lst->fmt, ind, (lst->in - ind) + 1);
	lst = recup_format(lst);
	pos = lst->in - ind;
	lst->conv = ft_strsub(lst->fmt, ind, (lst->in - ind) + 1);
	dispatch_one(lst, ap, pos);
	if (lst->neg == 1)
		lst = negative(lst);
	lst = concaten_result(lst, ind);
	lst = init_opt(lst);
	return (NULL);
}
