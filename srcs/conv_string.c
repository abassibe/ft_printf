/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 05:51:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/18 17:00:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*conv_ws(t_print *lst, wchar_t uni, int *j)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (uni <= 127)
	{
		lst->str[(*j)++] = uni;
		return (NULL);
	}
	tmp = ft_itoa_base_unicode(uni, 2);
	while (tmp[i])
	{
		if (tmp[i] == 'x')
			tmp[i] = '0';
		i++;
	}
	return (tmp);
}

static void		conv_ws_next(t_print *lst, int *j, char *str)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!str)
		return ;
	lst->tab = (int *)malloc(6);
	while (str[i])
	{
		tmp = ft_strsub(str, i, 8);
		lst->tab[c] = ft_btoi(tmp);
//		free(tmp);
//		tmp = NULL;
		i += 8;
		c++;
	}
	while (c < 5)
		lst->tab[c++] = 0;
	c = 0;
	while (lst->tab[c] != 0)
	{
		lst->str[(*j)++] = lst->tab[c++];
	}
//	lst->c_zero--;
//	free(str);
}

void	conv_s(t_print *lst, va_list ap)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (lst->l == 1)
	{
		if (!(lst->uni_str = va_arg(ap, wchar_t *)))
		{
			lst->str = ft_strdup("(null)");
			return ;
		}
		lst->str = ft_strnew(100);
		while (lst->uni_str[i])
		{
			tmp = conv_ws(lst, lst->uni_str[i++], &j);
			conv_ws_next(lst, &j, tmp);
		}
	}
	else
	{
		tmp = va_arg(ap, char *);
		lst->str = tmp;
	}
	if (lst->str == NULL)
		lst->str = ft_strdup("(null)");
	lst->len_str_conv = ft_strlen(lst->str);
}
