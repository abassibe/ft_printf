/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:09:47 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/09 04:22:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		c;
	char		*dst;

	c = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (int)ft_strlen(src) + 1)))
		return (NULL);
	while (c != ft_strlen(src))
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
	free(dst);
}
