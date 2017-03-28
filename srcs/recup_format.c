/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 02:07:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/27 17:43:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*recup_opt(t_print *lst, int *i)
{
	lst->opt = lst->conv[0];
	lst->conv++;
	lst->long_opt = ft_atoi(lst->conv);
	while (lst->conv[*i] >= 48 && lst->conv[*i] <= 57)
		(*i)++;
	return (lst);
}

t_print		*recup_preci(t_print *lst, int i)
{
	char	*tmp;

	tmp = ft_strsub(lst->conv, i + 1, (ft_strlen(lst->conv) - i));
	lst->conv++;
	lst->long_preci = ft_atoi(tmp);
	free(tmp);
	lst->got_opt = 1;
	return (lst);
}

t_print		*recup_flag(t_print *lst, int *i)
{
	if (lst->conv[*i] == 'h' && lst->conv[*i + 1] == 'h')
	{
		lst->taille = ft_strsub(lst->conv, *i, 2);
		(*i)++;
	}
	else if (lst->conv[*i] == 'h')
		lst->taille = ft_strsub(lst->conv, *i, 1);
	else if (lst->conv[*i] == 'l' && lst->conv[*i + 1] == 'l')
	{
		lst->taille = ft_strsub(lst->conv, *i, 2);
		(*i)++;
	}
	else if (lst->conv[*i] == 'l')
		lst->taille = ft_strsub(lst->conv, *i, 1);
	else if (lst->conv[*i] == 'j')
		lst->taille = ft_strsub(lst->conv, *i, 1);
	else if (lst->conv[*i] == 'z')
		lst->taille = ft_strsub(lst->conv, *i, 1);
	return (lst);
}

t_print		*recup_format(t_print *lst)
{
	int		i;

	i = 0;
	lst->long_preci = -1;
	lst->got_opt = 0;
	lst->taille = "ko";
	while (lst->conv[i])
	{
		if ((lst->conv[i] == '-' || lst->conv[i] == '+' || lst->conv[i] == '#'
				|| lst->conv[i] == '0' || lst->conv[i] == ' ')
				&& lst->got_opt != 1)
			lst = recup_opt(lst, &i);
		if (lst->conv[i] == '.')
			lst = recup_preci(lst, i);
		if (lst->conv[i] == 'h' || lst->conv[i] == 'l' || lst->conv[i] == 'j' ||
				lst->conv[i] == 'z')
			lst = recup_flag(lst, &i);
		i++;
	}
	return (lst);
}
