/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:43:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/13 23:39:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		double_percent(t_print *lst, char *perc)
{
	char	*comp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	comp = " -+0#hljz123456789.";
	while (perc[i])
	{
		j++;
		if (!comp[j])
		{
			i++;
			j = 0;
		}
		if (perc[i] == comp[j])
		{
			lst->conv = ft_strdup(perc);
//			free(perc);
			return ;
		}
		else if (!perc[i])
			lst->conv = ft_strnew(0);
	}
//	free(perc);
}

static void		simple_percent(t_print *lst, char *perc)
{
	char	*comp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	comp = " -+0#hljz123456789.";
	while (perc[i])
	{
		if (perc[i] == comp[j])
		{
			i++;
			j = 0;
		}
		else if (!comp[j])
		{
			lst->conv = ft_strsub(perc, 0, i);
//			free(perc);
			return ;
		}
		else
			j++;
	}
	lst->conv = ".0%";
//	free(perc);
}

static void		chk_percent(t_print *lst, char *corr_conv, int c, int ind)
{
	int		ci;

	ci = 0;
	while (lst->fmt[c] != corr_conv[ci])
	{
		ci++;
		if (lst->fmt[c] == '%')
		{
			double_percent(lst, ft_strsub(lst->fmt, ind, c - ind + 1));
			break ;
		}
		if (lst->fmt[c] == '\0')
		{
			simple_percent(lst, ft_strsub(lst->fmt, ind, c - ind + 1));
			break ;
		}
		if (!corr_conv[ci])
		{
			c++;
			ci = 0;
		}
	}
	if (lst->fmt[c] == corr_conv[ci])
		lst->conv = ft_strsub(lst->fmt, ind, c - ind + 1);
}

void			core(t_print *lst, va_list ap)
{
	char	*corr_conv;
	int		c;

	corr_conv = "sSpdDioOuUxXcC";
	c = 0;
	while (lst->fmt[c])
	{
		if (lst->fmt[c] == '%')
		{
			c++;
			chk_percent(lst, corr_conv, c, c);
			verif_format(lst, ap);
			c = concaten_result(lst, c);
//			free(lst->conv);
			init_opt(lst);
		}
		c++;
	}
}
