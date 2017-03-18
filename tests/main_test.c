/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:50:01 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/18 02:23:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	char	*str = L"䯂 䯂 䯂 䯂 䯂 䯂";
	char	*str2 = "simple test";
/*
	printf("Avec 30 de longueur :\n");
	printf("option '-' : |%-30s|\n", str);
	printf("option '+' : |%+30s|\n", str);
	printf("option '#' : |%#30s|\n", str);
	printf("option '0' : |%030s|\n", str);
	printf("option ' ' : |% 30s|\n", str);

	printf("Avec 3 de longueur :\n");
	printf("option '-' : |%-3s|\n", str);
	printf("option '+' : |%+3s|\n", str);
	printf("option '#' : |%#3s|\n", str);
	printf("option '0' : |%03s|\n", str);
	printf("option ' ' : |% 3s|\n", str);

	printf("Avec 10 de preci :\n");
	printf("option 'n' : |%.10s|\n", str);
	printf("option '-' : |%-30.10s|\n", str);
	printf("option '+' : |%+30.10s|\n", str);
	printf("option '#' : |%#30.10s|\n", str);
	printf("option '0' : |%030.10s|\n", str);
	printf("option ' ' : |% 30.10s|\n", str);

	printf("\nAvec 3 de preci :\n");
	printf("option 'n' : |%.3s|\n", str);
	printf("option '-' : |%-3.3s|\n", str);
	printf("option '+' : |%+3.3s|\n", str);
	printf("option '#' : |%#3.3s|\n", str);
	printf("option '0' : |%03.3s|\n", str);
	printf("option ' ' : |% 3.3s|\n", str);
*/
	printf("str sans uni\n");
	printf("test de s   : %s\n", str2);
	printf("test de hhs : %hhs\n", str2);
	printf("test de hs  : %hs\n", str2);
	printf("test de ls  : %ls\n", str2);
	printf("test de lls : %lls\n", str2);

	printf("str avec uni\n");
	printf("test de s   : %s\n", str);
	printf("test de hhs : %hhs\n", str);
	printf("test de hs  : %hs\n", str);
	printf("test de ls  : %ls\n", str);
	printf("test de lls : %lls\n", str);
	return (0);
}
