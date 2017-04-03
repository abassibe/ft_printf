/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:25:45 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/03 17:51:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*conv_h(t_print *lst, va_list ap)
{
	lst->s_int = va_arg(ap, int);
	lst->str_nb = ft_strdup(ft_itoa(lst->s_int));
	lst->len_str_nb = ft_strlen(lst->str_nb);
	if (lst->s_int < 0)
		lst->neg = 1;
	return (lst);
}

t_print		*conv_hh(t_print *lst, va_list ap)
{
	lst->c = va_arg(ap, int);
	lst->str_nb = ft_strdup(ft_itoa((int)lst->c));
	lst->len_str_nb = ft_strlen(lst->str_nb);
	if ((int)lst->c < 0)
		lst->neg = 1;
	return (lst);
}

t_print		*conv_l(t_print *lst, va_list ap)
{
	lst->l_int = va_arg(ap, long);
	lst->str_nb = ft_strdup(ft_itoa_long(lst->l_int));
	lst->len_str_nb = ft_strlen(lst->str_nb);
	if (lst->l_int < 0)
		lst->neg = 1;
	return (lst);
}

t_print		*conv_j(t_print *lst, va_list ap)
{
	lst->l_int = va_arg(ap, intmax_t);
	lst->str_nb = ft_strdup(ft_itoa_long(lst->l_int));
	lst->len_str_nb = ft_strlen(lst->str_nb);
	if (lst->l_int < 0)
		lst->neg = 1;
	return (lst);
}

t_print		*conv_z(t_print *lst, va_list ap)
{
	lst->size_t_i = va_arg(ap, size_t);
	lst->str_nb = ft_strdup(ft_itoa_long(lst->size_t_i));
	lst->len_str_nb = ft_strlen(lst->str_nb);
	return (lst);
}
