#include "ft_printf.h"

void	ft_cspec(t_args *ag, t_flags *fl)
{
	char c;

	c = (char) va_arg(ag->args, int);
	ft_putchar(c);
	fl->re += 1;
}
