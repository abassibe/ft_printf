/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/29 16:16:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*options_neg_i(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i < lenght)
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
	if (lst->long_opt <= lst->long_preci)
		lenght++;
	else if (lst->long_opt < lenght)
	{
		str[i++] = '+';
		lenght++;
	}
	while (i < lenght)
	{
		if (i == (lenght - ((int)ft_strlen(nb) + 1)))
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
//	if (lst->neg == 1 && lenght == ((int)ft_strlen(nb)))
//		lenght--;
//	if (lenght == ((int)ft_strlen(nb) + 1))
//		lenght--;
	while (i < lenght)
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
//	if (lst->neg == 1 && lenght == ((int)ft_strlen(nb)))
//		lenght--;
//	else if (lenght == ((int)ft_strlen(nb) + 1))
//		lenght--;
	while (i < lenght)
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
	if (lst->long_opt <= lst->long_preci)
		lenght++;
	else if (lst->long_opt < lenght)
	{
		str[i++] = ' ';
		lenght++;
	}
	while (i < lenght + 1)
	{
		if (i == (lenght - ((int)ft_strlen(nb) + 1)))
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
