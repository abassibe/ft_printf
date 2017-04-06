/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/05 23:57:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "ft_printf.h"

t_print		*options_neg(t_print *lst, char *str, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (lst->str[is] != '\0')
			str[i++] = lst->str[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*options_pos(t_print *lst, char *str, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (i >= (lenght - (int)ft_strlen(lst->str)))
			str[i++] = lst->str[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*options_zero(t_print *lst, char *str, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (i >= (lenght - (int)ft_strlen(lst->str)))
		{
			str[i++] = lst->str[is++];
		}
		else
			str[i++] = '0';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*convert_string(t_print *lst)
{
	char	*str;
	int		lenght;

	lenght = lst->long_opt;
	if (lenght < (int)ft_strlen(lst->str))
//	{
		lenght = (int)ft_strlen(lst->str);
		str = ft_strnew(lenght);
//	}
//	else
//		str = ft_strnew(lenght);
	if (lst->less == 1)
		lst = options_neg(lst, str, lenght);
	if (lst->plus == 1 || lst->diez == 1 || lst->space == 1)
		lst = options_pos(lst, str, lenght);
	if (lst->zero == 1)
		lst = options_zero(lst, str, lenght);
	return (lst);
}
