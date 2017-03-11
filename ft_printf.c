/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:27:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/11 02:15:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

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
	setlocale(LC_ALL, "");
//	char	*str;
//	char	c;
//	int		d;
	//char	*s;

//	str = "blablabla";
//	c = 'A';
//	d = 5;
	//s = "ksjdfd";
//	ft_printf("petit test avec une chaine :\n%s\nun char :\n%c\net un int :\n%d\npetit test avec une chaine :\n%s\nun char :\n%c\net un int :\n%d\n", str, c, d, str, c, d);
	//printf("%05.2s", s);
	printf("%d\n", INT_MAX);
	printf("%d\n", LONG_MAX);
	printf("%ld\n", LONG_MAX);
	printf("%D\n", LONG_MAX);
	printf("%s\n", "salut");
	printf("%S\n", L"allo ӦՂԞ");
	printf("%s\n", L"allo ӦՂԞ");
	printf("%ls\n", L"allo ӦՂԞ");
	printf("%s\n", "salut 2");
	return (0);
}
