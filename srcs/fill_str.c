/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:24:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/13 17:14:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_lst(const char *format, va_list ap)
{
	char	*valid;

	valid = "sSpdDioOuUxXcC";
	IND = 0;
	ARG = 0;
	FMT = ft_strdup(format); // malloc
	while (FMT[IND])
	{
		if (FMT[IND] == '%' && FMT[IND + 1] != '%')
		{

			ARG++;
			IND++;
		}
		IND++;
	}
}
