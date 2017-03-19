/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:18:37 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/19 05:30:28 by abassibe         ###   ########.fr       */
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
/*
	ft_printf("%d|our fucking printf\n", i);
	printf("%d|printf\n", i);
	printf("--------\n");
	ft_printf("%+20.20d|our fucking printf\n", i);
	printf("%+20.20d|printf +10.2\n", i);
	printf("--------\n");
	ft_printf("%+40.100d|our fucking printf\n", i);
	printf("%+40.100d|printf +10.4\n", i);
	printf("--------\n");
	ft_printf("%+50.100d|our fucking printf\n", i);
	printf("%+50.100d|printf +10.5\n", i);
	printf("--------\n");
	ft_printf("%-20.100d|our fucking printf\n", i);
	printf("%-20.100d|printf -10.2\n", i);
	printf("--------\n");
	ft_printf("%-40.100d|our fucking printf\n", i);
	printf("%-40.100d|printf -10.4\n", i);
	printf("--------\n");
	ft_printf("%-50.100d|our fucking printf\n", i);
	printf("%-50.100d|printf -10.5\n", i);
	printf("--------\n");
	ft_printf("%#20.100d|our fucking printf\n", i);
	printf("%#20.100d|printf #10.2\n", i);
	printf("--------\n");
	ft_printf("%#40.100d|our fucking printf\n", i);
	printf("%#40.100d|printf #10.4\n", i);
	printf("--------\n");
	ft_printf("%#50.100d|our fucking printf\n", i);
	printf("%#50.100d|printf #10.5\n", i);
	printf("--------\n");
	ft_printf("%020.100d|our fucking printf\n", i);
	printf("%020.100d|printf 010.2\n", i);
	printf("--------\n");
	ft_printf("%040.100d|our fucking printf\n", i);
	printf("%040.100d|printf 010.4\n", i);
	printf("--------\n");
	ft_printf("%050.100d|our fucking printf\n", i);
	printf("%050.100d|printf 010.5\n", i);
	printf("--------\n");
	ft_printf("% 20.100d|our fucking printf\n", i);
	printf("% 20.100d|printf  10.2\n", i);
	printf("--------\n");
	ft_printf("% 40.100d|our fucking printf\n", i);
	printf("% 40.100d|printf  10.4\n", i);
	printf("--------\n");
	ft_printf("% 50.100d|our fucking printf\n", i);
	printf("% 50.100d|printf  10.5\n", i);
	printf("--------\n");*/
	ft_printf("%.10hd|h\n", i);
	printf("%.10hd|h printf\n", i);
	ft_printf("%.10hhd|hh\n", i);
	printf("%.10hhd|hh printf\n", i);
	ft_printf("%.10ld|l\n", i);
	printf("%.10ld|l printf\n", i);
	ft_printf("%.10lld|ll\n", i);
	printf("%.10lld|ll printf\n", i);
	ft_printf("%.10jd|j\n", i);
	printf("%.10jd|j printf\n", i);
	ft_printf("%.10zd|z\n", i);
	printf("%.10zd|z printf\n", i);
	return (0);
}
