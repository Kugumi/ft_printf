#include "ft_printf.h"

int		lennbrf(double x)
{
	int	i;

	i = 0;
	if (x < 0)
		x = x * -1.0;
	while (x >= 1)
	{
		x = x / 10.0;
		i++;
	}
	return (i);
}

int		ft_lastbit(double x)
{
	unsigned long		*ptr;

	ptr = (unsigned long *)&x;
	return (*ptr >> 63);
}
