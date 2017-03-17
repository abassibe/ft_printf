/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concaten_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:22:49 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/17 05:17:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_print		*concaten_result(t_print *lst, int ind)
{
	char	*tmp;

	tmp = ft_strsub(lst->fmt, 0, ind - 1);
	printf("%s\n", tmp);
	tmp = ft_strjoin(tmp, lst->str);
	printf("%s\n", tmp);
	tmp = ft_strjoin(tmp, ft_strsub(lst->fmt, (lst->in + 1), ft_strlen(lst->fmt)));
	printf("%s\n", tmp);
	lst->fmt = tmp;
	return (lst);
}
