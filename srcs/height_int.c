/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:31:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/31 15:56:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*height_int(t_print *lst, int pos)
{
	if (ft_strcmp("hh", lst->taille) == 0)
	{
		while (lst->i > 127)
			lst->i -= 256;
		while (lst->i < -128)
			lst->i += 256;
		if (lst->i >= 0)
			lst->neg = 0;
	}
	else if (ft_strcmp("h", lst->taille) == 0)
	{
		while (lst->i > 32767)
			lst->i -= 65536;
		while (lst->i < -32768)
			lst->i += 65536;
		if (lst->i >= 0)
			lst->neg = 0;
	}
	lst->taille = "ko";
	return (lst);
}
