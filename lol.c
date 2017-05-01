#include <stdio.h>
#include <unistd.h>


float pow_two(int n)
{
	if (n < 0)
	{
		n = -n;
		return (1 / (2 * pow_two(n - 1)));
	}
	if (n == 0)
		return (1);
	return (2 * pow_two(n - 1));
}

float read_float(unsigned int n, int pow)
{
	if (n <= 0)
		return (0);
	return ((n % 2) * pow_two(pow) + read_float(n / 2, pow + 1));
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


int main(void)
{
	float f;
	float f2;
	unsigned int d;
	int sign;
	int exp;
	int mantisse;

	f = -3141.5;
	d = *(unsigned int*)(&f);
	sign = d >> 31;
	printf("Sign %d\n", sign);

	exp = (d << 1) >> 24;
	print_bin(exp, 8); printf("\n");
	printf("Exp %d\n", exp - 127);

	mantisse = (d << 9) >> 9;
	print_bin(mantisse, 32); printf("\n");
	print_bin(mantisse, 23); printf("\n");
	mantisse = ((exp >> 7) << 23) | mantisse;
	print_bin((exp >> 7) << 23, 24); printf("\n");
	print_bin(mantisse, 24); printf("\n");
	printf("Mantisse %d\n", mantisse);
	f2 = read_float(mantisse, 11 - 23);
	printf("Floato novo %f\n", f2);

	int entier = (mantisse >> (23 - 11));
	if (f - (float)entier > 0.5)
		entier++;
//	else if ()
//		entier++;

	printf("%d\n", entier);
	return (1);
}
