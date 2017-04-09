/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 02:07:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/09 06:05:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*recup_opt(t_print *lst, int i)
{
	if (lst->conv[i] == '+')
		lst->plus = 1;
	if (lst->conv[i] == '-')
		lst->less = 1;
	if (lst->conv[i] == '#')
		lst->diez = 1;
	if (lst->conv[i] == '0' &&
			!(lst->conv[i - 1] > '0' && lst->conv[i - 1] <= '9'))
		lst->zero = 1;
	if (lst->conv[i] == ' ')
		lst->space = 1;
	if (lst->plus == 1 && lst->space == 1)
		lst->space = 0;
	if (lst->less == 1 && lst->zero == 1)
		lst->zero = 0;
	return (lst);
}

t_print		*lenght_field(t_print *lst, int *i)
{
	lst->long_opt = ((int)lst->conv[(*i)++] - 48);
	while (lst->conv[(*i)] >= 48 && lst->conv[(*i)] <= 57)
	{
		lst->long_opt *= 10;
		lst->long_opt += ((int)lst->conv[(*i)++] - 48);
	}
	return (lst);
}

t_print		*recup_preci(t_print *lst, int *i)
{
	(*i)++;
	lst->long_preci = 0;
	while (lst->conv[(*i)] >= 48 && lst->conv[(*i)] <= 57)
	{
		lst->long_preci *= 10;
		lst->long_preci += ((int)lst->conv[(*i)++] - 48);
	}
	return (lst);
}

t_print		*recup_flag(t_print *lst, int *i)
{
	if (lst->conv[*i] == 'h' && lst->conv[*i + 1] == 'h')
	{
		lst->hh = 1;
		(*i)++;
	}
	else if (lst->conv[*i] == 'h')
		lst->h = 1;
	else if (lst->conv[*i] == 'l' && lst->conv[*i + 1] == 'l')
	{
		lst->ll = 1;
		(*i)++;
	}
	else if (lst->conv[*i] == 'l')
		lst->l = 1;
	else if (lst->conv[*i] == 'j')
		lst->j = 1;
	else if (lst->conv[*i] == 'z')
		lst->z = 1;
	return (lst);
}

t_print		*recup_format(t_print *lst)
{
	int		i;

	i = 0;
	while (lst->conv[i])
	{
		if (lst->conv[i] == '-' || lst->conv[i] == '+' || lst->conv[i] == '#'
				|| lst->conv[i] == '0' || lst->conv[i] == ' ')
			lst = recup_opt(lst, i);
		if (lst->conv[i] > 48 && lst->conv[i] < 58)
			lst = lenght_field(lst, &i);
		if (lst->conv[i] == '.')
			lst = recup_preci(lst, &i);
		if (lst->conv[i] == 'h' || lst->conv[i] == 'l' || lst->conv[i] == 'j' ||
				lst->conv[i] == 'z')
			lst = recup_flag(lst, &i);
		i++;
	}
	return (lst);
}
