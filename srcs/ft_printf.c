/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:27:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/16 04:41:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_print		*crea_lst(const char *format)
{
	t_print		*new;

	new = (t_print *)malloc(sizeof(t_print));
	new->fmt = format;
	return (new);
}

int		ft_printf(const char *format, ...)
{
	char		*ret;
	t_print		*lst;
	va_list		ap;

	va_start(ap, format);
	lst = crea_lst(format);
//	chk_error(format, aq); //A voir plus tard
	ret = core(lst, ap);
	va_end(ap);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
