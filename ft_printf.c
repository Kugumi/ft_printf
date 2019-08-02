#include <printf.h>

int ft_ spec(const char * restrict format)
{
	int f;

	f = 0;
	if (format[f] == '%')
	{
		f++;
		if (format[f] == '%')
			return (0);
		while(format[f] != '%')
		{

		}
	}
}

int printf(const char * restrict format, ...)
{
	int i;
	int f;

	i = 0;
	f = 0;
	while (format[f])
	{

	}
	return (i);
}
