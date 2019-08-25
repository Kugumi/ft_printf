#include "ft_printf.h"

void	ft_cspec(t_args *ag, const char *restrict fo)
{
	char c;

	c = (char) va_arg(ag->args, int);
	ft_putchar(c);
	ag->re += 1;
}
