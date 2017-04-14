/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:43:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/14 16:24:09 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		chk_flags(t_print *lst, char *comp, int c, int ind)
{
	int		ci;

	ci = 0;
	if (lst->fmt[c] == '%')
	{
		lst->conv = ft_strdup("%");
		return ;
	}
	while (comp[ci])
	{
		if (lst->fmt[c] == comp[ci])
		{
			c++;
			ci = 0;
		}
		else
			ci++;
	}
	if (!ft_strchr("sSpdDioOuUxXcC%", lst->fmt[c]))
		c--;
	lst->conv = ft_strsub(lst->fmt, ind, c - ind + 1);
}

void			core(t_print *lst, va_list ap)
{
	char	*comp;
	int		c;

	comp = " -+0#hljz123456789.";
	c = 0;
	while (lst->fmt[c])
	{
		if (lst->fmt[c] == '%')
		{
			c++;
			chk_flags(lst, comp, c, c);
			verif_format(lst, ap);
			c = concaten_result(lst, c);
//			free(lst->conv);
			init_opt(lst);
		}
		c++;
	}
}
