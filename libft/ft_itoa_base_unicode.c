/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:18:04 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/17 17:14:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*compte(int value)
{
	char	*ret;

	if (value <= 2047)
		ret = ft_strdup("110xxxxx10xxxxxx");
	else if (value <= 32767)
		ret = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else if (value <= 524287)
		ret = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	else if (value <= 8388607)
		ret = ft_strdup("111110xx10xxxxxx10xxxxxx10xxxxxx10xxxxxx");
	else
		ret = ft_strdup("1111110x10xxxxxx10xxxxxx10xxxxxx10xxxxxx10xxxxxx");
	return (ret);
}

char			*ft_itoa_base_unicode(int value, int base)
{
	char	*retour;
	int		nb;
	int		i;
	char	*tab;

	tab = "0123456789abcdef";
	if (value == 0)
		return (ft_strdup("0"));
	retour = compte(value);
	nb = ft_strlen(retour);
	i = 1;
	while (value != 0)
	{
		while (retour[nb - i] != 'x')
			i++;
		retour[nb - i] = tab[value % base];
		value /= base;
		i++;
	}
	return (retour);
}
