/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:27:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/11 01:11:40 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./libft/libft.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			d;
	char		c;
	char		*s;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
			}
			if (format[i] == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
			if (format[i] == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
			i++;
		}
		write(1, &format[i], 1);
		i++;
	}
	return (0);
}

int		main(void)
{
	char	*str;
	char	c;
	int		d;

	str = "blablabla";
	c = 'A';
	d = 5;
	ft_printf("petit test avec une chaine :\n%s\nun char :\n%c\net un int :\n%d\n", str, c, d);
	return (0);
}
