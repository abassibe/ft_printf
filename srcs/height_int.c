/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:31:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/28 16:25:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*height_int(t_print *lst, int pos)
{
	if (ft_strcmp("hh", lst->taille) == 0)
		while (lst->i > 127)
			lst->i -= 256;
	lst->taille = "ko";
	return (lst);
}
