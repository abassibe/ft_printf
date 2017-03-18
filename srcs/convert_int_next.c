/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/18 06:40:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*options_neg_i(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (nb[is] != '\0')
			str[i++] = nb[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*options_pos_i(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (i == ((lenght - (int)ft_strlen(nb)) - 1))
			str[i++] = '+';
		else if (i >= (lenght - (int)ft_strlen(nb)))
			str[i++] = nb[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*options_diez_i(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	if (lenght == ((int)ft_strlen(nb) + 1))
		lenght--;
	while (i != lenght)
	{
		if (i >= (lenght - (int)ft_strlen(nb)))
			str[i++] = nb[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*options_zero_i(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	if (lenght == ((int)ft_strlen(nb) + 1))
		lenght--;
	while (i != lenght)
	{
		if (i >= (lenght - (int)ft_strlen(nb)))
			str[i++] = nb[is++];
		else
			str[i++] = '0';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}

t_print		*options_sp_i(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (i == ((lenght - (int)ft_strlen(nb)) - 1))
			str[i++] = ' ';
		else if (i >= (lenght - (int)ft_strlen(nb)))
			str[i++] = nb[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	lst->str = ft_strdup(str);
	free(str);
	return (lst);
}
