
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int			main(void)
{
	setlocale(LC_ALL, "");
/*	char	*s;
	int		d;*/
	int		c = INT_MAX;
	signed char x[10] = "blabla";
	signed char z = 'A';
	unsigned char q[10] = "blabla";
	unsigned char w = 'A';
	short r = 10;
	unsigned short y = 10;
	unsigned int u = 10;
	long i = 10;
	unsigned long o = 10;
	long long p = 10;
	unsigned long long a = 10;
	double s = 0.15;
	float d = 0.15;
	wchar_t *f = L"䯂 䯂 䯂 䯂 䯂 䯂" ;
	wchar_t g = L'䯂';
	char	*adresse = "xdfhfgn";
	unsigned int		h = 10;
	int		j = 65536;

/*	d = 12;
	printf("___TEST FT_PRINTF___\n");
	ft_printf("int max %d\n", INT_MAX);
	ft_printf("long max d %d\n", LONG_MAX);
	ft_printf("long max ld  %ld\n", LONG_MAX);
	ft_printf("long max D %D\n", LONG_MAX);
	ft_printf("%S\n", L"䯂 : large group of horses traveling in a line");
	ft_printf("%s\n", L"䯂 : large group of horses traveling in a line");
	ft_printf("%ls\n", L"䯂 : large group of horses traveling in a line");
	printf("___TEST PRINTF___\n");
	printf("%d\n", INT_MAX);
	printf("%d\n", LONG_MAX);
	printf("%ld\n", LONG_MAX);
	printf("%D\n", LONG_MAX);
	printf("%S\n", L"䯂 : large group of horses traveling in a line");
	printf("%s\n", L"䯂 : large group of horses traveling in a line");
	printf("%ls\n", L"䯂 : large group of horses traveling in a line");
	printf("signed char * : %s\n", x);
	printf("signed char : %c\n", z);
	printf("unsigned char * : %s\n", q);
	printf("unsigned char : %c\n", w);
	printf("short : %i\n", r);
	printf("unsigned short : %d\n", y);
	printf("unsigned int : %u\n", u);
	printf("long : %li\n", i);
	printf("unsigned long : %zu\n", o);
	printf("long long : %lli\n", p);
	printf("unsigned long long : %llu\n", a);
	printf("double : %f\n", s);
	printf("float : %f\n", d);
	printf("long char * : %S\n", f);
	printf("long char : %lc\n", g);
	printf("adresse : %p\n", &adresse);
	printf("int hexa : %u\n", h);
	printf("test h : %hd\n", j);
	printf("%d\n", USHRT_MAX);*/
	printf("%hd\n", c);
	return (0);
}
