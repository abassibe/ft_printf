/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negative_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:17:36 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/29 16:18:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*neg_plus(t_print *lst)
{
	int		i;

	i = 0;
	if (lst->str[i] == '+')
	{
		lst->str[i] = '-';
		return (lst);
	}
	while (lst->str[i] && lst->str[i] != '+')
	{
		i++;
		if (lst->str[i] == '+')
		{
			lst->str[i] = '-';
			return (lst);
		}
	}
	return (lst);
}

t_print		*neg_preci(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	tmp = (char *)malloc(ft_strlen(lst->str) + 1);
	tmp[0] = '-';
	if (lst->str[i] == ' ')
		i++;
	while (lst->str[i])
		tmp[j++] = lst->str[i++];
	lst->str = ft_strdup(tmp);
	free(tmp);
	return (lst);
}

t_print		*neg(t_print *lst)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 1;
	tmp = (char *)malloc(ft_strlen(lst->str));
	tmp[0] = '-';
	while (j < ft_strlen(lst->str))
		tmp[j++] = lst->str[i++];
	tmp[j] = '\0';
	lst->str = ft_strdup(tmp);
	free(tmp);
	return (lst);
}

t_print		*neg_opt(t_print *lst)
{
	int		i;

	i = 0;
	if (lst->opt == '-')
		lst = neg(lst);
	else if (lst->long_preci > (int)ft_strlen(ft_itoa(lst->i)))
		lst->str[ft_strlen(lst->str) - lst->long_preci - 1] = '-';
	else
		while (lst->str[i])
		{
			if (lst->str[i] == '0')
			{
				lst->str[i] = '-';
				break;
			}
			if (lst->str[i] > '0' && lst->str[i] <= '9')
			{
				lst->str[i - 1] = '-';
				break;
			}
			i++;
		}
	return (lst);
}
