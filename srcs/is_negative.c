/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:17:21 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/30 15:47:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*negative(t_print *lst)
{
	if (lst->long_preci == 0 && lst->neg == 1)
		return (lst);
	if (ft_strchr(lst->str, '+'))
		lst = neg_plus(lst);
	else if (lst->long_preci >= lst->long_opt)
		lst = neg_preci(lst);
	else if (lst->long_preci < lst->long_opt)
		lst = neg_opt(lst);
	return (lst);
}
