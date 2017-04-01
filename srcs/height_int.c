/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:31:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 18:55:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*height_int_next(t_print *lst, va_list ap, int pos)
{
	if (ft_strcmp("l", lst->taille) == 0)
		lst->l_int = va_arg(ap, long int);
	else
		lst->i = va_arg(ap, int);
	return (lst);
}

t_print		*height_int(t_print *lst, va_list ap, int pos)
{
	if (ft_strcmp("hh", lst->taille) == 0)
	{
		lst->i = va_arg(ap, int);
		while (lst->i > 127)
			lst->i -= 256;
		while (lst->i < -128)
			lst->i += 256;
		if (lst->i >= 0)
			lst->neg = 0;
	}
	else if (ft_strcmp("h", lst->taille) == 0)
	{
		lst->i = va_arg(ap, int);
		while (lst->i > 32767)
			lst->i -= 65536;
		while (lst->i < -32768)
			lst->i += 65536;
		if (lst->i >= 0)
			lst->neg = 0;
	}
	else
		lst = height_int_next(lst, ap, pos);
	return (lst);
}
