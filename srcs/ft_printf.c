/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:27:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 05:08:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_print		*lst;
	va_list		ap;

	va_start(ap, format);
	lst = crea_lst(format);
	init_opt(lst);
	lst->ind_cut = 0;
	lst->len_ret = 0;
	core(lst, ap);
	init_opt(lst);
	chk_color(lst);
	va_end(ap);
	ft_putnstr(lst->fmt, lst->len_ret);
//	ft_strdel(&lst->conv);
//	free(lst->fmt);
//	free(lst);
	if (lst->bool_star == 1)
		write(1, "\033[0;0m", 7);
	return (lst->len_ret);
}

int				ft_sprintf(char **str, const char *format, ...)
{
	t_print		*lst;
	va_list		ap;

	va_start(ap, format);
	lst = crea_lst(format);
	init_opt(lst);
	lst->ind_cut = 0;
	lst->len_ret = 0;
	core(lst, ap);
	init_opt(lst);
	va_end(ap);
	*str = ft_strdup(lst->fmt);
//	free(lst->fmt);
//	free(lst);
	return (lst->len_ret);
}

int				ft_fprintf(int fd, const char *format, ...)
{
	t_print		*lst;
	va_list		ap;

	va_start(ap, format);
	lst = crea_lst(format);
	init_opt(lst);
	lst->ind_cut = 0;
	lst->len_ret = 0;
	core(lst, ap);
	init_opt(lst);
	va_end(ap);
	write(fd, lst->fmt, lst->len_ret);
//	free(lst->fmt);
//	free(lst);
	return (lst->len_ret);
}
