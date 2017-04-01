/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:17:21 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 20:56:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*negative(t_print *lst)
{
	if (ft_strchr(lst->str, '+'))
		lst = neg_plus(lst);
	else if (lst->long_preci >= lst->long_opt)
		lst = neg_preci(lst);
	else if (lst->long_opt <= ft_strlen(ft_itoa(lst->i)))
		lst = neg_preci(lst);
	else if (ft_strcmp("l", lst->taille) == 0 && lst->long_opt <= ft_strlen(ft_itoa_long(lst->l_int)))
		lst = neg_preci(lst);
	else if (lst->opt == '-')
		lst = neg_moins(lst);
	else
		lst = neg(lst);
	return (lst);
}
