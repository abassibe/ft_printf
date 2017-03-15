/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:25:42 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/13 15:28:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chk_error(const char *format, va_list aq)
{
	int		count;

	count = 0;
	IND = 0;
	while (format[IND])
	{
		if (format[IND] == '%' && format[IND + 1] != '%')
		{
			count++;
			IND++;
		}
		IND++;
	}
	return (0);
}
