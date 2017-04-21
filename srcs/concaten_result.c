/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concaten_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:22:49 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/21 17:16:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		concaten_result(t_print *lst, int ind)
{
	char	*tmp;
	char	*cpy;
	int		len_conv;
	int		i;

	len_conv = 0;
	cpy = ft_strdup(lst->str);
	len_conv = (int)ft_strlen(lst->conv);
	tmp = ft_strjoin(ft_strsub(lst->fmt, 0, ind - 1), cpy);
	i = (int)ft_strlen(tmp) - 1;
	tmp = ft_strjoin(tmp, ft_strsub(lst->fmt, ind + len_conv,
				ft_strlen(lst->fmt) - ind + len_conv));
//	free(lst->fmt);
	lst->fmt = ft_strdup(tmp);
//	free(tmp);
//	free(lst->str);
	return (i);
}
