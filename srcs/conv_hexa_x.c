/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:31:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/08 16:11:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		hexa_diez(t_print *lst, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	if (lst->long_opt == 0 && lst->long_preci == 0 && lst->l_hexa == 0)
		return ;
	tmp = ft_strnew(lst->len_str + 2);
	while (i < lst->len_str + 2)
	{
		if (i < lst->len_str - ((int)ft_strlen(lst->str_nb)) &&
				(lst->str_nb[0] != '0' || lst->str_nb[1] == 'x'))
			tmp[i++] = ' ';
		else if (i < lst->len_str - ((int)ft_strlen(lst->str_nb)))
			tmp[i++] = '0';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

static void		hexa_less(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->diez == 1)
		lst->len_str_conv += 2;
	tmp = ft_strnew(lst->len_str);
	while (j < lst->len_str_conv)
		tmp[i++] = lst->str_nb[j++];
	while (i < lst->len_str)
		tmp[i++] = ' ';
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

static void		hexa_field(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->long_opt == 0)
		return ;
	tmp = ft_strnew(lst->len_str);
	while (i < lst->len_str)
	{
		if (i < lst->len_str - ((int)ft_strlen(lst->str_nb)))
			tmp[i++] = ' ';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

static void		preci_hexa(t_print *lst, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	if (lst->long_preci == -1 &&
			(lst->long_opt > lst->len_str_conv && lst->zero == 1))
		lst->len_str_conv = lst->long_opt;
	if (lst->long_preci == 0 && lst->l_hexa == 0)
	{
		ft_strdel(&lst->str_nb);
		lst->str_nb = ft_strnew(0);
		return ;
	}
	else
		tmp = ft_strnew(lst->len_str_conv);
	while (i < lst->len_str_conv)
	{
		if (i < (lst->len_str_conv - (int)ft_strlen(lst->str_nb)))
			tmp[i++] = '0';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

void			conv_hexa_x(t_print *lst)
{
	int		i;

	i = 0;
	lst->len_str_conv = (int)ft_strlen(lst->str_nb);
	if (lst->long_preci > lst->len_str_conv)
		lst->len_str_conv = lst->long_preci;
	lst->len_str = lst->len_str_conv;
	if (lst->long_opt > lst->len_str)
		lst->len_str = lst->long_opt;
	if (lst->diez == 1 && lst->str_nb[0] != 0 && lst->long_preci != 0)
		lst->long_opt -= 2;
	preci_hexa(lst, i);
	if (lst->diez == 1 && lst->l_hexa != 0)
		lst->str_nb = ft_strjoinfn("0x", lst->str_nb);
	if (lst->less == 1)
		hexa_less(lst);
	else if (lst->diez == 1)
		hexa_diez(lst, i);
	else
		hexa_field(lst);
	lst->str = lst->str_nb;
	lst->len_str_conv = (int)ft_strlen(lst->str);
}
