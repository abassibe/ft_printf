/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:31:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/27 18:34:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	//Seul le cas hh a gerer.
	//Le cas hh a gerer (modifie la valeur de l'int) et convertir en short avec h et long avec l.
#include "../includes/ft_printf.h"

t_print		*height_int(t_print *lst, int pos)
{
	if (ft_strcmp("hh", lst->taille) == 0)
		while (lst->i > 127)
			lst->i -= 256;
	lst->taille = "ko";
	return (lst);
}
