/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:31:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/16 05:59:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_print		*convert_string(t_print *lst, int pos)
{
	if (lst->conv[0] == '-')
	{
		lst->conv++;
		options(lst, ft_itoa(lst->conv), '-');
	}
	if (lst->conv[0] == '+')
	{
		lst->conv++;
		options(lst, ft_itoa(lst->conv), '+');
	}
	if (lst->conv[0] == '#')
	{
		lst->conv++;
		options(lst, ft_itoa(lst->conv), '#');
	}
	if (lst->conv[0] == '0')
	{
		lst->conv++;
		options(lst, ft_itoa(lst->conv), '0');
	}
	if (lst->conv[0] == ' ')
	{
		lst->conv++;
		options(lst, ft_itoa(lst->conv), ' ');
	}
	return (lst);
}
