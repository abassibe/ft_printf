/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:18:37 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/17 04:46:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int		i = 10;
	char	c = 'A';
	char	*str = "Hello world";
	ft_printf("un int %015.6hhs, puis u%%%%n char %-20.5jc et une chaine %-10.4lld%.....\n", str, c, i);
	return (0);
}
