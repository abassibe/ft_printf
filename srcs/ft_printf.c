/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:27:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/15 05:48:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
//	va_list		aq;
	char		*ret;

	OUT_S = 0;
	create_lst();
	va_start(ap, format);
//	va_copy(aq, ap);
//	chk_error(format, aq); //A voir plus tard
//	va_end(aq);
	ret = core(format, ap);
	va_end(ap);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
