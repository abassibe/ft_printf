/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:43:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/04 14:10:59 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*chk_conv(t_print *lst, char *corr_conv, va_list ap, int ind)
{
	int		ci;

	ci = 0;
	while (lst->fmt[lst->in] != corr_conv[ci])
	{
		if (lst->fmt[lst->in] == '\0'/* || lst->fmt[lst->i] == '\n'*/)
			break ;
		ci++;
		if (!corr_conv[ci])
		{
			lst->in++;
			ci = 0;
		}
	}
	if (lst->fmt[lst->in] == corr_conv[ci])
	{
		verif_format(lst, ap, ind);
		lst->in++;
	}
	return (lst);
}

int		chk_percent(t_print *lst, char *ret, va_list ap, int *c)
{
	char	*corr_conv;
	int		ci;
	int		ind;

	ci = 0;
	corr_conv = "sSpdDioOuUxXcC";
	if (lst->fmt[lst->in] == '%' && lst->fmt[lst->in + 1] == '%')
	{
		ret[*c] = '%';
		lst->in++;
		return (1);
	}
	if (lst->fmt[lst->in] == '%' && lst->fmt[lst->in + 1] != '%')
	{
		ind = lst->in + 1;
		lst->in++;
		lst = chk_conv(lst, corr_conv, ap, ind);
	}
	if (lst->fmt[lst->in] == '\0')
		return (0);
	ret[*c] = lst->fmt[lst->in];
	return (1);
}

char	*core(t_print *lst, va_list ap)
{
	int		c;
	char	*ret;

	lst->in = 0;
	c = 0;
	ret = ft_strnew(ft_strlen(lst->fmt));
	while (chk_percent(lst, &(*ret), ap, &c) == 1)
	{
		lst->in++;
		c++;
	}
	return (ret);
}
