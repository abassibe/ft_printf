/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_l_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:22:38 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 21:15:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*preci_l_int_next(t_print *lst, char *nb, int lenght)
{
	int i;

	i = 0;
	while (i < lenght - (int)ft_strlen(nb))
	{
		if (i < (lenght - lst->long_preci))
			lst->str[i] = ' ';
		else
			lst->str[i] = '0';
		i++;
	}
	if (lst->opt == '+')
	{
		if (lst->long_preci <= (int)ft_strlen(nb))
		{
			if (lst->long_preci != 0 || lst->l_int > -9223372036854775807)
				lst->str[i - 1] = '+';
			else 
				lst->str[i] = '+';
		}
		else
			lst->str[lenght - lst->long_preci - 1] = '+';
	}
//	printf("%s\n", lst->str);
	return (lst);
}

t_print		*preci_l_int_neg_next(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		j;

	i = lenght - lst->long_preci;
	if (lst->long_preci <= (int)ft_strlen(nb))
		i = 0;
	j = 1;
	str[0] = '-';
	if (lst->long_preci < lst->long_opt)
		while (lst->str[i])
		{
			str[j++] = lst->str[i++];
			if (!lst->str[i])
				while (j < lenght)
					str[j++] = ' ';
		}
	else
		while (lst->str[i])
			str[j++] = lst->str[i++];
	str[j] = '\0';
	lst->str = ft_strdup(str);
	return (lst);
}

t_print		*preci_l_int_neg(t_print *lst, char *str, char *nb, int lenght)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (lst->l_int < -9223372036854775807)
		lst = preci_l_int_neg_next(lst, &(*str), nb, lenght);
	else
	{
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
	}
	return (lst);
}

t_print		*preci_l_int_noopt(t_print *lst, char *str, char *nb, int lenght)
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
		if (lst->long_preci <= (int)ft_strlen(nb))
			str[i - 1] = '+';
		else
			str[lenght - lst->long_preci - 1] = '+';
	}
	while (lst->str[c])
		str[i++] = lst->str[c++];
	lst->str = ft_strdup(str);
	return (lst);
}

t_print		*preci_l_int(t_print *lst)
{
	int		lenght;
	char	*str;
	char	*nb;

	if (lst->long_preci == -1)
	{
		if (lst->l_int < 0)
			lst->neg = 1;
		return (lst);
	}
	nb = ft_itoa_long(lst->l_int);
	lenght = ft_strlen(lst->str);
	if (lenght < lst->long_preci)
		lenght = lst->long_preci;
	str = ft_strnew(lenght + 1);
	if (lst->opt == '-')
		preci_l_int_neg(lst, str, nb, lenght);
	else if (lst->opt == 0)
		preci_l_int_noopt(lst, str, nb, lenght);
	else
		preci_l_int_next(lst, nb, lenght);
	free(str);
	return (lst);
}
