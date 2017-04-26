/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:54:16 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/26 19:41:01 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		set_tab(char *str)
{	
	static char		*tab1[11];
	static char		*tab2[11];
	int				i;

	i = 0;
	tab1[0] = "{eoc}";
	tab2[0] = "\033[0;0m";
	tab1[1] = "{bold}";
	tab2[1] = "\033[0;1m";
	tab1[2] = "{ita}";
	tab2[2] = "\033[0;3m";
	tab1[3] = "{und}";
	tab2[3] = "\033[0;4m";
	tab1[4] = "{light}";
	tab2[4] = "\033[0;7m";
	tab1[5] = "{red}";
	tab2[5] = "\033[0;031m";
	tab1[6] = "{green}";
	tab2[6] = "\033[0;32m";
	tab1[7] = "{yellow}";
	tab2[7] = "\033[0;33m";
	tab1[8] = "{blue}";
	tab2[8] = "\033[0;34m";
	tab1[9] = "{purple}";
	tab2[9] = "\033[0;35m";
	tab1[10] = "{cyan}";
	tab2[10] = "\033[0;36m";
	
	while (i < 10)
	{
		printf("1 - str = %s\n", str);
		printf("2 - tab1[%d] = [%s]\n", i, tab2[i]);
		if (!(ft_strcmp(str, tab1[i])))
			return (1);
		i++;
	}
	return (0);
}

void			chk_color(t_print *lst)
{
	int				i;
	int				j;
	int				c;
	char			*tmp;

	i = 0;
	j = 0;
	c = 0;
	tmp = ft_strnew(10);
	while (lst->fmt[i])
	{
		if (lst->fmt[i] == '{')
		{
			j = i;	
			while (lst->fmt[j] != '}' && lst->fmt[j] && c < 10)
			{
				tmp[c++] = lst->fmt[j++];
				if (lst->fmt[j + 1] == '}')
					tmp[c + 1] = lst->fmt[j + 1];
			}
			set_tab(tmp);
		}
		i++;
	}
}
