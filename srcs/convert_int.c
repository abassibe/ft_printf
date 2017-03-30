/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/30 17:22:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*init_opt(t_print *lst)
{
	lst->opt = 0;
	lst->long_opt = 0;
	lst->long_preci = -1;
	lst->neg = 0;
	lst->str = NULL;
	return (lst);
}

t_print		*convert_int(t_print *lst)
{
	char	*str;
	char	*nb;
	int		lenght;

	nb = ft_itoa(lst->i);
	lst->str = nb;
	lenght = lst->long_opt;
	if (lenght < lst->long_preci)
		lenght = lst->long_preci;
	if (lenght <= (int)ft_strlen(nb))
		lenght = (int)ft_strlen(nb);
	str = ft_strnew(lenght);
	if (lst->opt == '-' && (lst->long_preci != 0 || lenght > ft_strlen(nb)))
		lst = options_neg_i(lst, str, nb, lenght);
	else if (lst->opt == '+' && (lst->long_preci != 0 || lst->i != -2147483648))
		lst = options_pos_i(lst, str, nb, lenght);
	else if (lst->opt == '#' || lst->long_preci == 0)
		lst = options_diez_i(lst, str, nb, lenght);
	else if (lst->opt == '0')
		lst = options_zero_i(lst, str, nb, lenght);
	else if (lst->opt == ' ' && lst->i != -2147483648)
		lst = options_sp_i(lst, str, nb, lenght);
	return (lst);
}
