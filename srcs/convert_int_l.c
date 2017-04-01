/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/01 20:43:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*convert_int_l(t_print *lst)
{
	char	*str;
	char	*nb;
	int		lenght;

	nb = ft_itoa_long(lst->l_int);
	if (lst->l_int < -9223372036854775807)
		nb = ft_strdup("9223372036854775808");
	lst->str = nb;
	lenght = lst->long_opt;
	if (lenght < lst->long_preci)
		lenght = lst->long_preci;
	if (lenght <= (int)ft_strlen(nb))
		lenght = (int)ft_strlen(nb);
	str = ft_strnew(lenght);
	if (lst->opt == '-' && ft_strcmp("9223372036854775808", nb) != 0)
		lst = options_neg_i(lst, str, nb, lenght);
	if (lst->opt == '+' && ft_strcmp("9223372036854775808", nb) != 0)
		lst = options_pos_i(lst, str, nb, lenght);
	if (lst->opt == '#' && ft_strcmp("9223372036854775808", nb) != 0)
		lst = options_diez_i(lst, str, nb, lenght);
	if (lst->opt == '0' ||ft_strcmp("9223372036854775808", nb) == 0)
		lst = options_zero_i(lst, str, nb, lenght);
	if (lst->opt == ' ' && ft_strcmp("9223372036854775808", nb) != 0)
		lst = options_sp_i(lst, str, nb, lenght);
	return (lst);
}
