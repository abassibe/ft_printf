/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:30:53 by maviot            #+#    #+#             */
/*   Updated: 2017/03/11 05:22:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
/*
struct typedef			s_arg
{
	char				c;
	char				*s;
	long char			*lstr;
	int					d;
	long int			ld;
	long long			lld;
	unsigned int		ud;
}						t_arg;*/
