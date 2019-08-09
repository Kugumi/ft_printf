#include "ft_printf.h"

void ft_dspec(const char *restrict format, va_list args)
{
	int l;

	l = va_arg(args, int);
	ft_putstr(ft_itoa(l));
}
int ft_spec(const char * restrict format, t_flags *fl)
{
	int f;

	f = 1;
	if (format[f] == '%')
		return (0);
	while (format[f] != 'c' && format[f] != 'd' /*|| format[f] != 'p' || format[f] != 'i' || format[f] != 'o' || format[f] != 'u' || format[f] != 'x' || format[f] !=
				'X' || format[f] != 'f' || format[f] != 'l' || format[f] != 'h' || format[f] != 'L'*/)
	{
		if (format[f] == '-')
		{
			write(1, "bya", 3);
		}
	}
	if (format[f] == 'd')
		ft_dspec(format + f, fl->args);
	return (1);
}

int ft_printf(const char * restrict format, ...)
{
	t_flags fl;
	va_start(fl.args, format);

	int i;
	int f;

	i = 0;
	f = 0;
	while (format[f])
	{
		while (format[f] == '%')
		{
			if ((ft_spec(format + f, &fl)) == 0)
			{
				write(1, "%", 1);
				i++;
				f += 2;
			}
		}
		write(1, &format[f], 1);
		i++;
		f++;
	}
	va_end(fl.args);
	return (i);
}
int main()
{
	int d = 127;
	ft_printf("%%%d", d);
}
