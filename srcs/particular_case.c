/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:48:31 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 15:03:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*i_zero(t_print *lst)
{
	int		i;

	i = 0;
	if (lst->long_preci == 0 && lst->long_opt == 0)
	{
		lst->str = ft_strnew(0);
		return (lst);
	}
	if (lst->i == 0 && lst->long_preci == 0)
	{
		lst->str = ft_strnew(lst->long_opt);
		while (i < lst->long_opt)
			lst->str[i++] = ' ';
		if (lst->opt == '+')
		lst->str[i - 1] = '+';
	}
	return (lst);
}
