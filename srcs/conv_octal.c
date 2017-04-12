/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:31:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/12 19:53:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		octal_less(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(lst->len_str);
	while (j < lst->len_str_conv)
		tmp[i++] = lst->str_nb[j++];
	while (i < lst->len_str)
		tmp[i++] = ' ';
	lst->str_nb = tmp;
}

static void		octal_field(t_print *lst)
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
	lst->str_nb = tmp;
}

static void		preci_octal(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->long_preci == 0 && lst->str_nb[0] == '0' && lst->diez != 1)
	{
		lst->str_nb = ft_strnew(0);
		if (lst->long_opt == 0)
			lst->len_str = 0;
		return ;
	}
	if (lst->long_preci == -1 &&
			(lst->long_opt > lst->len_str_conv && lst->zero == 1))
		lst->len_str_conv = lst->long_opt;
	tmp = (char *)malloc(lst->len_str_conv);
	while (i < lst->len_str_conv)
	{
		if (i < (lst->len_str_conv - (int)ft_strlen(lst->str_nb)))
			tmp[i++] = '0';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	lst->str_nb = tmp;
}

static void		recup_arg(t_print *lst, va_list ap)
{
	if (lst->hh == 1)
	{
		lst->us_c = va_arg(ap, int);
		lst->usll_int = lst->us_c;
	}
	else if (lst->l == 1 || lst->ll == 1)
	{
		lst->l_int = va_arg(ap, long);
		lst->usll_int = lst->l_int;
	}
	else if (lst->j == 1)
	{
		lst->l_int = va_arg(ap, intmax_t);
		lst->usll_int = lst->l_int;
	}
	else if (lst->z == 1)
	{
		lst->size_t_i = va_arg(ap, size_t);
		lst->usll_int = lst->size_t_i;
	}
	else
	{
		lst->us_int = va_arg(ap, int);
		lst->usll_int = lst->us_int;
	}
}

void			conv_octal(t_print *lst, va_list ap)
{
	if (lst->h == 1)
	{
		lst->uss_int = va_arg(ap, int);
		lst->usll_int = lst->uss_int;
	}
	else
		recup_arg(lst, ap);
	if (lst->diez == 1 && lst->usll_int > 0)
		lst->str_nb = ft_strjoin("0", ft_itoa_base_unsigned(lst->usll_int, 8));
	else
		lst->str_nb = ft_itoa_base_unsigned(lst->usll_int, 8);
	lst->len_str_conv = ft_strlen(lst->str_nb);
	if (lst->long_preci > lst->len_str_conv)
		lst->len_str_conv = lst->long_preci;
	lst->len_str = lst->len_str_conv;
	if (lst->long_opt > lst->len_str)
		lst->len_str = lst->long_opt;
	preci_octal(lst);
	lst->str = ft_strnew(lst->len_str);
	if (lst->less == 1)
		octal_less(lst);
	else
		octal_field(lst);
	lst->str = ft_strdup(lst->str_nb);
}
