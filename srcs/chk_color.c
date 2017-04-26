/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:54:16 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/26 17:41:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		set_tab(char *str)
{
	static char		**tab[11];
	int				i;

	i = 0;
	*tab[0] = "{eoc}";
	tab[0][0] = "\033[0;0m";
	*tab[1] = "{bold}";
	tab[1][0] = "\033[0;1m";
	*tab[2] = "{ita}";
	tab[2][0] = "\033[0;3m";
	*tab[3] = "{und}";
	tab[3][0] = "\033[0;4m";
	*tab[4] = "{light}";
	tab[4][0] = "\033[0;7m";
	*tab[5] = "{red}";
	tab[5][0] = "\033[0;031m";
	*tab[6] = "{green}";
	tab[6][0] = "\033[0;32m";
	*tab[7] = "{yellow}";
	tab[7][0] = "\033[0;33m";
	*tab[8] = "{blue}";
	tab[8][0] = "\033[0;34m";
	*tab[9] = "{purple}";
	tab[9][0] = "\033[0;35m";
	*tab[10] = "{cyan}";
	tab[10][0] = "\033[0;36m";
	while (i < 10)
	{
		if (!(ft_strcmp(str, *tab[i])))
			printf("%stest\n", tab[i][0]);
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
	while (lst->str[i])
	{
		if (lst->str[i] == '{')
		{
			j = i;
			while (lst->str[j] != '}' && lst->str[j] && c < 10)
				tmp[c++] = lst->str[j++];
			set_tab(tmp);
		}
		i++;
	}
}
