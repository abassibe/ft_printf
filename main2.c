/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:37:19 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/21 19:26:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <string.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "da_DK");
	int		k = 0;
	int		h = 0;
	int		i = 12345678;
	int		j = 10;
	float	f = 10000.51;
	wchar_t	uni = L'α';

	char	c;
	wchar_t *str = L"α α α α";

	k = printf("%'d", i);
	printf("\n");
//	h = ft_printf("%2$d %2$#x", 16, 54854);
	printf("\n");
	printf("k = %d, h = %d\n", k, h);
	/*TEST A REVOIR
	printf("----- test 18-2 -----\n");
	i = printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("\n");
	j = ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test 43-22 -----\n");
	i = printf("%hhC, %hhC", 0, L'米');
	printf("\n");
	j = ft_printf("%hhC, %hhC", 0, L'米');
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test 50-5 -----\n");
	i = printf("{%3c}", 0);
	printf("\n");
	j = ft_printf("{%3c}", 0);
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test 52-7 -----\n");
	i = printf("{%03c}", 0);
	printf("\n");
	j = ft_printf("{%03c}", 0);
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test 62-6 -----\n");
	i = printf("{% c}", 0);
	printf("\n");
	j = ft_printf("{% c}", 0);
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test 62-11 -----\n");
	i = printf("{% C}", 0);
	printf("\n");
	j = ft_printf("{% C}", 0);
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test 79-4 -----\n");
	i = printf("{%05.c}", 0);
	printf("\n");
	j = ft_printf("{%05.c}", 0);
	printf("\n");
	printf("i = %d, j = %d\n", i, j);
	printf("----- test bonus 01-4 -----\n");
	k = printf("{%*c}", 0, 0);
	printf("\n");
	h = ft_printf("{%*c}", 0, 0);
	printf("\n");
	printf("k = %d, h = %d\n", k, h);
	printf("----- test bonus 01-5 -----\n");
	k = printf("{%.*d}", -5, 42);
	printf("\n");
	h = ft_printf("{%.*d}", -5, 42);
	printf("\n");
	printf("k = %d, h = %d\n", k, h);
	printf("----- test bonus 01-7 -----\n");
	k = printf("{%.*d}", -5, 42);
	printf("\n");
	h = ft_printf("{%.*d}", -5, 42);
	printf("\n");
	printf("k = %d, h = %d\n", k, h);
	printf("----- test bonus 01-10 -----\n");
	k = printf("{%.*s}", -5, "42");
	printf("\n");
	h = ft_printf("{%.*s}", -5, "42");
	printf("\n");
	printf("k = %d, h = %d\n", k, h);
	*/
	////write(1, &i, 1);
	////write(		1, &j, 1);
	////write(1, "\n", 1);
	////ft_printf("\033[32mbonjour\033[37mh		ello\n");
	////ft_printf("\n");
	////ft_printf("%%\n");
	////ft_printf("%d\n"			, 42);
	////ft_printf("%d%d\n", 42, 41);
	////ft_printf("%d%d%d\n", 42, 43,		 44);
	////ft_printf("%ld\n", 2147483647);
	////ft_printf("%lld\n", 9223372		036854775807);
	////ft_printf("%x\n", 505);
	////ft_printf("%X\n", 505);
	////			printf("%p\n", &ft_printf);
	////ft_printf("%p\n", &ft_printf);
	////ft_pr		intf("%20.15d\n", 54321);
	////ft_printf("%-10d\n", 3);
	////ft_printf("% d		\n", 3);
	////ft_printf("%+d\n", 3);
	////ft_printf("%010d\n", 1);
	////ft_pr			intf("%hhd\n", 0);
	////ft_printf("%jd\n", 9223372036854775807);
	////ft_pr		intf("%zd\n", 4294967295);
	////ft_printf("%\n");
	////ft_printf("%U\n", 42		94967295);
	////ft_printf("%u\n", 4294967295);
	////ft_printf("%o\n", 40);
	//		//ft_printf("%%#08x\n", 42);
	//		//ft_printf("%x\n", 1000);
	//		//ft_printf(			"%#X\n", 1000);
	//		//ft_printf("%s\n", NULL);
	//		//ft_printf("%S\n", L"ݗݜ		शব");
	//		//ft_printf("%s%s\n", "test", "test");
	//		//ft_printf("%s%s%s\		n", "test", "test", "test");
	//		//ft_printf("%C\n", 15000);

	/*
	printf("------------- %% ---------------\n");
	printf("%%|printf\n");
	ft_printf("%%|\n");
	printf("%.0%|.0 printf\n");
	ft_printf("%.0%|.0\n");
	printf("%.5%|.5 printf\n");
	ft_printf("%.5%|.5\n");
	printf("%5%|5 printf\n");
	ft_printf("%5%|5\n");
	printf("% 5%| 5 printf\n");
	ft_printf("% 5%| 5\n");
	printf("%-5%|-5 printf\n");
	ft_printf("%-5%|-5\n");
	printf("%+5%|+5 printf\n");
	ft_printf("%+5%|+5\n");
	printf("%05%|05 printf\n");
	ft_printf("%05%|05\n");
	printf("%#5%|#5 printf\n");
	ft_printf("%#5%|#5\n");
	printf("% 5.2%| 5.2 printf\n");
	ft_printf("% 5.2%| 5.2\n");
	printf("%-5.2%|-5.2 printf\n");
	ft_printf("%-5.2%|-5.2\n");
	printf("%+5.2%|+5.2 printf\n");
	ft_printf("%+5.2%|+5.2\n");
	printf("%05.2%|05.2 printf\n");
	ft_printf("%05.2%|05.2\n");
	printf("%#5.2%|#5.2 printf\n");
	ft_printf("%#5.2%|#5.2\n");
	printf("% 5.10%| 5.10 printf\n");
	ft_printf("% 5.10%| 5.10\n");
	printf("%-5.10%|-5.10 printf\n");
	ft_printf("%-5.10%|-5.10\n");
	printf("%+5.10%|+5.10 printf\n");
	ft_printf("%+5.10%|+5.10\n");
	printf("%05.10%|05.10 printf\n");
	ft_printf("%05.10%|05.10\n");
	printf("%#5.10%|#5.10 printf\n");
	ft_printf("%#5.10%|#5.10\n");
	printf("%Z| printf\n");
	ft_printf("%Z|\n");
	printf("% hZ| printf\n");
	ft_printf("% hZ|\n");
	printf("% hZ%| printf\n");
	ft_printf("% hZ%|\n");
	printf("% Z| printf\n", "test");
	ft_printf("% Z|\n", "test");
	printf("% Z | printf\n", "test");
	ft_printf("% Z |\n", "test");
	printf("% Z%s| printf\n", "test");
	ft_printf("% Z%s|\n", "test");*/
		return (0);
}
