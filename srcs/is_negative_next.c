/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negative_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:17:36 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 21:07:39 by abassibe         ###   ########.fr       */
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
	tmp = (char *)malloc(ft_strlen(lst->str) + 2);
	if (lst->str[i] == ' ')
		i++;
	tmp[0] = '-';
	if (lst->str[0] == '-')
		j--;
	while (lst->str[i])
		tmp[j++] = lst->str[i++];
	tmp[j] = '\0';
	lst->str = ft_strdup(tmp);
	free(tmp);
	return (lst);
}

t_print		*neg_moins(t_print *lst)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 1;
	len = ft_strlen(lst->str);
	tmp = (char *)malloc(len + 1);
	tmp[0] = '-';
	if (lst->str[0] == '-')
		j--;
	while (i < len)
		tmp[j++] = lst->str[i++];
	tmp[j] = '\0';
	lst->str = ft_strdup(tmp);
	free(tmp);
	return (lst);
}

t_print		*neg_next(t_print *lst, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 1;
	if (lst->str[0] == ' ')
	{
		lst->str[ft_strlen(lst->str) - len - 1] = '-';
		return (lst);
	}
	tmp = (char *)malloc(ft_strlen(lst->str) + 2);
	tmp[0] = '-';
	while (lst->str[i])
		tmp[j++] = lst->str[i++];
	tmp[j] = '\0';
	lst->str = ft_strdup(tmp);
	free(tmp);
	return (lst);
}

t_print		*neg(t_print *lst)
{
	int		i;
	int		len;

	i = 0;
	len = lst->long_preci;
	if (lst->long_preci == -1)
		len = lst->long_opt;
	if (lst->long_preci >= (int)ft_strlen(ft_itoa(lst->i)))
		lst = neg_next(lst, len);
	else if (lst->str[0] == '0')
		lst->str[0] = '-';
	else
	{
		while (!(lst->str[i] > 48 && lst->str[i] <= 57))
			i++;
		lst->str[i - 1] = '-';
	}
	return (lst);
}
