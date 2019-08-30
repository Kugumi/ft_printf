#include "ft_printf.h"

void	ft_cspec(t_args *ag, t_flags *fl)
{
	char c;

	c = (char) va_arg(ag->args, int);
	if (!fl->mi)
		ft_flag(fl, 1, 1);
	else
		ft_flagmi(fl, 1, 1);
	ft_putchar(c);
	if (fl->mi)
	{
		if (fl->wdh > 1)
		{
			fl->wdh -= 1;
			while (fl->wdh)
			{
				write(1, " ", 1);
				fl->wdh -= 1;
				fl->re += 1;
			}
		}
	}
	fl->re += 1;
}
