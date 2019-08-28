#include "ft_printf.h"

t_flags	ft_filltf(t_flags *fl)
{
    fl->mi = 0;
    fl->pl = 0;
    fl->ze = 0;
    fl->oc = 0;
    fl->sp = 0;
    fl->wdh = 0;
	fl->psn = -1;
	fl->lnh = 0;
	fl->re = 0;
	return (*fl);
}

void	ft_wdh(const char *restrict fo, t_flags *fl)
{
	char buff[11];
	int i;

	i = 0;
	while (fo[i] >= 48 && fo[i] <= 57)
	{
		buff[i] = fo[i];
		i++;
	}
	buff[i] = '\0';
	fl->wdh = ft_atoi(buff);
}

int	ft_psn(const char *restrict fo, t_flags *fl)
{
	char buff[11];
	int i;
	int f;

	i = 0;
	f = 1;
	if (!(fo[f] >= 48 && fo[f] <= 57))
	{
		fl->psn = 0;
		return (0);
	}
	else
	{
		while (fo[f] >= 48 && fo[f] <= 57)
		{
			buff[i] = fo[f];
			i++;
			f++;
		}
		buff[i] = '\0';
	}
	fl->psn = ft_atoi(buff);
	return (1);
}
