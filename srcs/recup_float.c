/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 22:48:05 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/01 06:04:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*convert_bin(unsigned int n, int len)
{
	char	*tmp;
	int		i;

	i = len - 1;
	if (len == 0)
		return (NULL);
	tmp = ft_strnew(len);
	while (len > 0)
	{
		if (n % 2)
			tmp[i--] = '1';
		else
			tmp[i--] = '0';
		n /= 2;
		len--;
	}
	return (tmp);
}

static void		round_dec(t_print *lst, char *dec)
{
	int		i;
	int		count;
	float	tmp;

	i = 0;
	count = 0;
	tmp = 2;
	lst->dec = 0;
	while (dec[i])
	{
		if (i == 0 && dec[i] == '1')
			lst->dec += (1 / tmp);
		else if (i != 0 && dec[i] == '1')
		{
			while (count++ < i)
				tmp *= 2;
			lst->dec += (1 / tmp);
		}
		count = 0;
		tmp = 2;
		i++;
	}
	ft_strdel(&dec);
}

void  print_bin(unsigned int n, int ss)
{
	if (ss == 0)
		return ;
	print_bin(n / 2, ss - 1);
	if (n % 2)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

void			recup_float(t_print *lst, va_list ap)
{
	unsigned int	d;
	int				exp;
	int				mantisse;
	char			*tmp;

	lst->f = (float)va_arg(ap, double);
	d = *(unsigned int *)(&lst->f);
	lst->neg = d >> 31;
	exp = (d << 1) >> 24;
	mantisse = (d << 9) >> 9;
	lst->ent = (mantisse << 9) >> 1;
	lst->ent = lst->ent | 1u << 31;
	lst->ent = lst->ent >> (31 - (exp - 127));
	lst->dec = mantisse << (exp + 10);
	tmp = convert_bin(lst->dec, 32);
	lst->str = ft_itoa(lst->ent);
	round_dec(lst, tmp);
}
