/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:57:28 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/20 18:40:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_empty(t_print *lst, char c)
{
	int		i;

	i = 0;
	lst->len_str = 1;
	if (lst->long_opt > lst->len_str)
		lst->len_str = lst->long_opt;
	lst->str = ft_strnew(lst->len_str);
	if (lst->less == 1)
	{
		lst->str[i++] = c;
		while (i < lst->long_opt)
			lst->str[i++] = ' ';
	}
	else if (lst->zero == 1)
	{
		while (i < lst->long_opt - 1)
			lst->str[i++] = '0';
		lst->str[i] = c;
	}
	else
	{
		while (i < lst->long_opt - 1)
			lst->str[i++] = ' ';
		lst->str[i] = c;
	}
}
