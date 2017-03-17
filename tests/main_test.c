/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:50:01 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/17 02:49:43 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char	*str = "simple test";
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
	printf("test de %.2.4.5s\n", str);
	return (0);
}
