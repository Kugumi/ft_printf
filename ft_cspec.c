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

void	ft_sspec(t_args *ag, t_flags *fl)
{
	char	*str;
	int		i;
	int		s;

	i = 0;
	str = va_arg(ag->args, char *);
	if (str == NULL)
		str = "(null)";
	if (!fl->mi)
		ft_flagstr(fl, str);
	else
		s = ft_flagstrmi(fl, str);
	if (fl->mi)
	{
	    if (fl->psn == -1)
		{
			if (fl->wdh > 0)
			{
			//fl->wdh -= (int)j;
				while (fl->wdh)
				{
					write(1, " ", 1);
					fl->wdh -= 1;
					fl->re += 1;
				}
			}
		}
		else if (fl->psn == 0)
		{
			while (fl->wdh)
			{
				write(1, " ", 1);
				fl->wdh -= 1;
				fl->re += 1;
			}
		}
		else
		{
			if (fl->wdh > 0)
			{
				while (fl->wdh)
				{
					write(1, " ", 1);
					fl->wdh -= 1;
					fl->re += 1;
				}
			}
		}
	}
}
