/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:22:38 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/18 07:03:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*preci_int_next(t_print *lst, char *str, char *nb, int lenght)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i <= lenght)
	{
		if (lst->long_preci > ft_strlen(nb))
		{
			str[i] = '0';
			lst->long_preci--;
		}
		else
		{
			str[i] = lst->str[c];
			c++;
		}
		i++;
	}
	return (lst);
}

t_print		*preci_int(t_print *lst)
{
	int		lenght;
	char	*str;
	char	*nb;

	nb = ft_itoa(lst->i);
	lenght = ft_strlen(lst->str);
	if (lst->long_preci > lenght)
	{
		str = ft_strnew(lst->long_preci);
		lenght = lst->long_preci;
	}
	else
		str = ft_strnew(lenght);
	preci_int_next(lst, str, nb, lenght);
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}
