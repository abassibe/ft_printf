/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/19 05:31:09 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*convert_int(t_print *lst)
{
	char	*str;
	char	*nb;
	int		lenght;

	lenght = 0;
	nb = ft_itoa(lst->i);
	lst->str = nb;
	lenght = lst->long_opt;
	if (lenght < lst->long_preci)
		lenght = lst->long_preci;
	if (lenght <= (int)ft_strlen(nb))
		lenght = (int)ft_strlen(nb);
	str = ft_strnew(lenght);
	if (lst->opt == '-')
		lst = options_neg_i(lst, str, nb, lenght);
	if (lst->opt == '+')
		lst = options_pos_i(lst, str, nb, lenght);
	if (lst->opt == '#')
		lst = options_diez_i(lst, str, nb, lenght);
	if (lst->opt == '0')
		lst = options_zero_i(lst, str, nb, lenght);
	if (lst->opt == ' ')
		lst = options_sp_i(lst, str, nb, lenght);
	return (lst);
}
