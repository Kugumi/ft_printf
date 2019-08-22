#include "ft_printf.h"

int ft_flagsdi(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'l' && fo[f] != 'h'
			&& fo[f] != '.' && !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
			fl->mi = !(fl->ze = 0) ? 1 : 1;
		else if (fo[f] == '+')
			fl->pl = !(fl->sp = 0) ? 1 : 1;
		else if (fo[f] == ' ')
			fl->sp = !(fl->pl) ? 1 : 0;
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else
			return (-1);
		f++;
	}
	if (fo[f] >= 48 && fo[f] <= 57)
		ft_wdh(fo + f, fl);
	return (1);
}

int ft_flagscsp(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'c' && fo[f] != 's' && fo[f] != 'p' && fo[f] != '.'
			&& !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
			fl->mi = 1;
		else
			return (-1);
		f++;
	}
	if (fo[f] >= 48 && fo[f] <= 57)
		ft_wdh(fo + f, fl);
	return (1);
}

int ft_flagsf(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'f' && fo[f] != '.' && fo[f] != 'l' && fo[f] != 'L' &&
			!(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
			fl->mi = !(fl->ze = 0) ? 1 : 1;
		else if (fo[f] == '+')
			fl->pl = !(fl->sp = 0) ? 1 : 1;
		else if (fo[f] == ' ')
			fl->sp = !(fl->pl) ? 1 : 0;
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else if (fo[f] == '#')
			fl->oc = 1;
		else
			return (-1);
		f++;
	}
	if (fo[f] >= 48 && fo[f] <= 57)
		ft_wdh(fo + f, fl);
	return (1);
}

int ft_flagsu(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'u' && fo[f] != '.' && fo[f] != 'l' && fo[f] != 'h'
			&& !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
		{
			if ((fl->mi = 1) && !(fl->ze = 0))
				;
		}
		else if (fo[f] == '0')
		{
			if ((!fl->mi))
				fl->ze = 1;
		}
		else
			return (-1);
		f++;
	}
	if (fo[f] >= 48 && fo[f] <= 57)
		ft_wdh(fo + f, fl);
	return (1);
}

int ft_flagsoxX(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'o' && fo[f] != 'x' && fo[f] != 'X' && fo[f] != '.'
			&& fo[f] != 'l' && fo[f] != 'h' && !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
		{
			if ((fl->mi = 1) && !(fl->ze = 0))
				;
		}
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else if (fo[f] == '#')
			fl->oc = 1;
		else
			return (-1);
		f++;
	}
	if (fo[f] >= 48 && fo[f] <= 57)
		ft_wdh(fo + f, fl);
	return (1);
}
