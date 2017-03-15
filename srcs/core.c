/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:43:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/15 05:51:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		chk_conv(const char *format, char *corr_conv, int i, int ind)
{
	int		ci;

	ci = 0;
	while (format[i] != corr_conv[ci])
	{
		if (format[i] == '\0' || format[i] == '\n')
			return (0);
		ci++;
		if (!corr_conv[ci])
		{
			i++;
			ci = 0;
		}
	}
	if (format[i] == corr_conv[ci])
	{
		// OUT[OUT_S] = ft_strsub(format, ); les defines C COOOOL mabite
		i++;
	}
	return (i);
}

int		chk_percent(const char *format, char *ret, int *i, int *c)
{
	char	*corr_conv;
	int		ci;
	int		ind;

	ci = 0;
	corr_conv = "sSpdDioOuUxXcC";
	if (format[*i] == '%' && format[(*i) + 1] == '%')
	{
		ret[*c] = '%';
		(*i)++;
		return (1);
	}
	if (format[*i] == '%' && format[(*i) + 1] != '%')
	{
		ind = *i + 1;
		(*i)++;
		*i = chk_conv(format, corr_conv, *i, ind);
	}
	if (format[*i] == '\0')
		return (0);
	ret[*c] = format[*i];
	return (1);
}

char	*core(const char *format, va_list ap)
{
	int		i;
	int		c;
	char	*ret;

	i = 0;
	c = 0;
	ap = NULL;
	ret = ft_strnew(ft_strlen(format));
	while (chk_percent(format, &(*ret), &i, &c) == 1)
	{
		i++;
		c++;
	}
	return (ret);
}
