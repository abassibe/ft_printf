/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 03:38:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/01 04:06:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		creat_str(t_print *lst, long i)
{
	struct lconv		*lc;

	lc = localeconv();
	if (lst->neg == 1)
		lst->str = ft_strjoinfn("-", lst->str);
	if (lc->decimal_point[0])
		lst->str = ft_strjoinff(lst->str, lc->decimal_point);
	else
		lst->str = ft_strjoinff(lst->str, ".");
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
