/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:22:38 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/19 05:07:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*preci_int_next(t_print *lst, char *nb, int lenght)
{
	int i;
	int limit;

	i = 0;
	limit = lenght - ft_strlen(nb);
	while (i < limit)
	{
		if (i < (lenght - lst->long_preci))
			lst->str[i] = ' ';
		else
			lst->str[i] = '0';
		i++;
	}
	if (lst->opt == '+')
	{
		if (lst->long_preci <= ft_strlen(nb))
			lst->str[i - 1] = '+';
		else
			lst->str[lenght - lst->long_preci - 1] = '+';
	}
	return (lst);
}

t_print		*preci_int_neg(t_print *lst, char *str, char *nb, int lenght)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i < lenght)
	{
		if (lst->str[c])
		{
			if (i < ((int)lst->long_preci - (int)ft_strlen(nb)))
				str[i++] = '0';
			else
				str[i++] = lst->str[c++];
		}
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	return (lst);
}

t_print		*preci_int_noopt(t_print *lst, char *str, char *nb, int lenght)
{
	int i;
	int c;
	int limit;

	i = 0;
	c = 0;
	limit = lenght - ft_strlen(nb);
	while (i < limit)
	{
		if (i < (lenght - lst->long_preci))
			str[i++] = ' ';
		else
			str[i++] = '0';
	}
	if (lst->opt == '+')
	{
		if (lst->long_preci <= ft_strlen(nb))
			str[i - 1] = '+';
		else
			str[lenght - lst->long_preci - 1] = '+';
	}
	while (lst->str[c])
		str[i++] = lst->str[c++];
	lst->str = ft_strdup(str);
	return (lst);
}

t_print		*preci_int(t_print *lst)
{
	int		lenght;
	char	*str;
	char	*nb;

	if (lst->long_preci == -1)
		return (lst);
	nb = ft_itoa(lst->i);
	lenght = ft_strlen(lst->str);
	if (lenght < lst->long_preci)
		lenght = lst->long_preci;
	str = ft_strnew(lenght);
	if (lst->opt == '-')
		preci_int_neg(lst, str, nb, lenght);
	else if (lst->opt == 0)
		preci_int_noopt(lst, str, nb, lenght);
	else
		preci_int_next(lst, nb, lenght);
	free(str);
	return (lst);
}
