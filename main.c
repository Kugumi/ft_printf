#include "ft_printf.h"

int main()
{
	int		i;
	double	d;

	i = 198;
	d = 1.7;
	ft_printf("Hello, this is double: %lf\tand this is an int: %i\n", d, i);
}
