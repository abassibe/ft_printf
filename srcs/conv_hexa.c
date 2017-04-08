/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:31:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/08 05:34:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		hexa_less(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(lst->len_str);
	while (j < lst->len_str_conv + 2)
		tmp[i++] = lst->str_nb[j++];
	while (i < lst->len_str)
		tmp[i++] = ' ';
	lst->str_nb = ft_strdup (tmp);
}

static void		hexa_field(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(lst->len_str);
	while (i < lst->len_str + 2)
	{
		if (i < lst->len_str - ((int)ft_strlen(lst->str_nb)))
			tmp[i++] = ' ';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	lst->str_nb = ft_strdup(tmp);
}

static void		preci_hexa(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->long_preci == -1 &&
			(lst->long_opt > lst->len_str_conv && lst->zero == 1))
		lst->len_str_conv = lst->long_opt - 2;
	tmp = (char *)malloc(lst->len_str_conv);
	while (i < lst->len_str_conv)
	{
		if (i < (lst->len_str_conv - (int)ft_strlen(lst->str_nb)))
			tmp[i++] = '0';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	lst->str_nb = ft_strdup(tmp);
}

void			conv_hexa(t_print *lst, va_list ap)
{
	char	*str;

	str = "0x";
	lst->l_hexa = va_arg(ap, long long);
	lst->str_nb = ft_itoa_base(lst->l_hexa, 16);
	lst->len_str_conv = ft_strlen(lst->str_nb);
	if (lst->long_preci > lst->len_str_conv)
		lst->len_str_conv = lst->long_preci;
	lst->len_str = lst->len_str_conv;
	if (lst->long_opt > lst->len_str)
		lst->len_str = lst->long_opt;
	preci_hexa(lst);
	lst->str = ft_strnew(lst->len_str);
	lst->str_nb = ft_strjoin(str, lst->str_nb);
	if (lst->less == 1)
		hexa_less(lst);
	else
		hexa_field(lst);
	lst->str = ft_strdup(lst->str_nb);
}