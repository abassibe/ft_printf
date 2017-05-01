/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 03:38:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/01 06:14:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		creat_str(t_print *lst, long i)
{
	struct lconv	*lc;
	char			*tmp;
	int				c;

	tmp = NULL;
	c = 0;
	lc = localeconv();
	if (lst->neg == 1)
		lst->str = ft_strjoinfn("-", lst->str);
	if (lc->decimal_point[0])
		lst->str = ft_strjoinff(lst->str, lc->decimal_point);
	else
		lst->str = ft_strjoinff(lst->str, ".");
	if (lst->dec == 0)
	{
		tmp = ft_strnew(lst->long_preci);
		while (c < lst->long_preci)
			tmp[c++] = '0';
		lst->str = ft_strjoinf(lst->str, tmp);
	}
	else
		lst->str = ft_strjoinf(lst->str, ft_itoa_long(i));
}

void			conv_float(t_print *lst)
{
	long	i;
	int		c;

	i = 0;
	c = 0;
	if (lst->long_preci == -1)
		lst->long_preci = 6;
	while (c < lst->long_preci)
	{
		lst->dec *= 10;
		c++;
	}
	i = (long)(lst->dec);
	creat_str(lst, i);
	lst->len_str_conv = (int)ft_strlen(lst->str);
}
