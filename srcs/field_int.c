/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:05:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/04 20:51:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*field_less(t_print *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->neg == 1)
		lst->str[i++] = '-';
	else if (lst->plus == 1)
		lst->str[i++] = '+';
	else if (lst->space == 1)
		lst->str[i++] = ' ';
	while (lst->str_nb[j])
		lst->str[i++] = lst->str_nb[j++];
	while (i < lst->len_str)
		lst->str[i++] = ' ';
	return (lst);
}

t_print		*field_plus(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_nb - 1;
	if ((lst->long_preci < lst->len_str_nb && lst->long_opt == lst->len_str_nb)
			|| lst->long_preci == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1)
		lst->str[i--] = '-';
	else
		lst->str[i--] = '+';
	while (i >= 0)
		lst->str[i--] = ' ';
	return (lst);
}

t_print		*field_zero(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_nb - 1;
	if (lst->long_preci == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1 && lst->long_preci != -1)
		lst->str[i--] = '-';
	while (i >= 0 && lst->long_preci > -1)
		lst->str[i--] = ' ';
	while (i >= 0 && lst->long_preci == -1)
		lst->str[i--] = '0';
	if (lst->long_preci == -1 && lst->neg == 1)
		lst->str[0] = '-';
	return (lst);
}

t_print		*field_space(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_nb - 1;
	if ((lst->long_preci < lst->len_str_nb && lst->long_opt == lst->len_str_nb)
			|| lst->long_preci == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1)
		lst->str[i--] = '-';
	else
		lst->str[i--] = ' ';
	while (i >= 0)
		lst->str[i--] = ' ';
	return (lst);
}

t_print		*field_diez(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_nb - 1;
	if (lst->long_preci == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1)
		lst->str[i--] = '-';
//	if (lst->long_opt == 0)
//		return (lst);
	while (i >= 0)
		lst->str[i--] = ' ';
	return (lst);
}

t_print		*field_int(t_print *lst)
{
	if (lst->less == 1)
		lst = field_less(lst);
	else if (lst->plus == 1)
		lst = field_plus(lst);
	else if (lst->zero == 1)
		lst = field_zero(lst);
	else if (lst->space == 1)
		lst = field_space(lst);
	else
		lst = field_diez(lst);
	return (lst);
}
