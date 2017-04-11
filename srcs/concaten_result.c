/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concaten_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:22:49 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/11 15:07:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		concaten_result(t_print *lst, int ind)
{
	char	*tmp;
	int		len_conv;
	int		i;

	len_conv = (int)ft_strlen(lst->conv);
	tmp = ft_strsub(lst->fmt, 0, ind - 1);
	tmp = ft_strjoin(tmp, lst->str);
	i = (int)ft_strlen(tmp) - 1;
	tmp = ft_strjoin(tmp, ft_strsub(lst->fmt, ind + len_conv,
				ft_strlen(lst->fmt) - ind + len_conv));
	lst->fmt = ft_strdup(tmp);
	free(tmp);
	return (i);
}
