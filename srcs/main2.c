/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:18:37 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/18 07:02:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		i = 1000;
//	char	c = 'A';
	char	*str = "Hello world";
	char	*str1 = "deuxieme phrase";
	char	*str2 = "troisieme";
//	char	*uni = L"䯂 䯂 䯂 䯂 䯂 䯂";
/*	ft_printf("un int %015.6s, puis u%%%%n char %-20.5s et une chaine %-10.4s%.....\n", uni, str1, str2);
	ft_printf("str sans uni\n");
	ft_printf("test de s   : %s\n", str);
	printf("test de s   : %s | printf\n", str);
	ft_printf("test de hhs : %hhs\n", str);
	printf("test de hhs : %hhs | printf\n", str);
	ft_printf("test de hs  : %hs\n", str);
	printf("test de hs  : %hs | printf\n", str);
	ft_printf("test de ls  : %ls\n", str);
	printf("test de ls  : %ls | printf\n", str);
	ft_printf("test de lls : %lls\n", str);
	printf("test de lls : %lls | printf\n", str);

	ft_printf("str avec uni\n");
	ft_printf("test de s   : %s\n", uni);
	printf("test de s   : %s | printf\n", uni);
	ft_printf("test de hhs : %hhs\n", uni);
	printf("test de hhs : %hhs | printf\n", uni);
	ft_printf("test de hs  : %hs\n", uni);
	printf("test de hs  : %hs | printf\n", uni);
	ft_printf("test de ls  : %ls\n", uni);
	printf("test de ls  : %ls | printf\n", uni);
	ft_printf("test de lls : %lls\n", uni);
	printf("test de lls : %lls | printf\n", uni);*/

	ft_printf("%+10.2d|\n", i);
	ft_printf("%+10.4d|\n", i);
	ft_printf("%+10.10d|\n", i);
	printf("%+10.2d|printf\n", i);
	printf("%+10.4d|printf\n", i);
	printf("%+10.5d|printf\n", i);
/*	printf("test de int : %d|    |%d|\n", i, i);
	printf("test de int '-' : %-3d||%-30d|\n", i, i);
	printf("test de int '+' : %+3d|%+30d|\n", i, i);
	printf("test de int '#' : %#3d||%#30d|\n", i, i);
	printf("test de int '0' : %03d||%030d|\n", i, i);
	printf("test de int ' ' : % 3d|% 30d|\n", i, i);*/
	return (0);
}
