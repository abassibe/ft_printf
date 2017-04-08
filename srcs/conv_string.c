/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 05:51:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/06 07:24:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_s(t_print *lst, va_list ap)
{
	char	*tmp;

//	if (lst->l == 1)
//	{
		// fait qqchose
//	}
//	else
		tmp = va_arg(ap, char *);
	lst->str = ft_strdup(tmp);
	if (tmp == NULL)
		lst->str = ft_strdup("(null)");
	lst->len_str_conv = ft_strlen(lst->str);
}