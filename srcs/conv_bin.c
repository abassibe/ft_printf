/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 03:26:28 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/04 01:49:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			conv_bin(t_print *lst, va_list ap)
{
	lst->l_int = va_arg(ap, long);
	lst->str = ft_itoa_base(lst->l_int, 2);
	lst->len_str_conv = (int)ft_strlen(lst->str);
}
