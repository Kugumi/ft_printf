#include "ft_printf.h"

void ft_dspec(t_flags *fl)
{
	int l;

	l = va_arg(fl->args, int);
	fl->re += ft_putstr(ft_itoa(l));
}
int ft_spec(const char * restrict format, t_flags *fl)
{
	unsigned long long f;

	f = 1;
	if (format[f] == '%')
		return (0);
	while (format[f] != 'c' && format[f] != 'd' /*|| format[f] != 'p' || format[f] != 'i' || format[f] != 'o' || format[f] != 'u' || format[f] != 'x' || format[f] !=
				'X' || format[f] != 'f' || format[f] != 'l' || format[f] != 'h' || format[f] != 'L'*/)
	{
		fl->len += 1;
		f++;
	}
	f = 1;
	while (format[f] != 'c' && format[f] != 'd' /*|| format[f] != 'p' || format[f] != 'i' || format[f] != 'o' || format[f] != 'u' || format[f] != 'x' || format[f] !=
				'X' || format[f] != 'f' || format[f] != 'l' || format[f] != 'h' || format[f] != 'L'*/)
	{
//		if (format[f] == '-')
//		{
			write(1, &format[f], 1);
			f++;
//		}
	}
	if (format[f] == 'd')
		ft_dspec(fl);
	return (1);
}

int ft_printf(const char * restrict format, ...)
{
	t_flags fl;
	unsigned long long f;
	fl = ft_filltf(&fl);
	va_start(fl.args, format);

	f = 0;
	while (format[f])
	{
		while (format[f] == '%')
		{
			if ((ft_spec(format + f, &fl)) == 0)
			{
				write(1, "%", 1);
				fl.re += 1;
				f += 2;
			}
			else
			{
				f += fl.len;
			}
		}
		write(1, &format[f], 1);
		fl.re += 1;
		f++;
	}
	va_end(fl.args);
	return (fl.re);
}
int main()
{
	int d = 127;
	int d1 = 0;
	ft_printf("hey, %% and %d oh, and you, %d, haha priv", d, d1);
}
