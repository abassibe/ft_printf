
#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	char	*str;
	char	c;
	int		d;

	str = "blablabla";
	c = 'A';
	d = 5;
	ft_printf("petit test avec une chaine :\n%s\nun char :\n%c\net un int :\n%d\n", str, c, d);
	return (0);
}
