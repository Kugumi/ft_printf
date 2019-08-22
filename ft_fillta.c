#include "ft_printf.h"

t_args ft_fillta(t_args *ag)
{
	ag->re = 0;
	ag->len = 2;
	return (*ag);
}

t_flags	ft_filltf(t_flags *fl)
{
    fl->mi = 0;
    fl->pl = 0;
    fl->ze = 0;
    fl->oc = 0;
    fl->sp = 0;
    fl->wdh = 0;
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
