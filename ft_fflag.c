#include "ft_printf.h"

void	ft_fflag(t_flags *fl, char *s)
{
	char *buff;
	int i;
	int r;

	r = (int)ft_strlen(s);
	fl->re += r;
	i = 0;
	buff = (char *)malloc(sizeof(char));
	buff[i] = '\0';
	if (fl->pl)
	{
		if (!(s[0] == '-'))
		{
			buff = ft_strjoin(buff, "+");
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	else if (fl->sp && s[0] != '-')
	{
		buff = ft_strjoin(buff, " ");
		fl->wdh -= 1;
		fl->re += 1;
	}
	if (fl->wdh > r)
	{
		fl->wdh -= r;
		while (fl->wdh)
		{
			if (fl->ze)
				buff = ft_strjoin(buff, "0");
			else
				buff = ft_strjoin(" ", buff);
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	while(buff[i] != '\0')
		write(1, &buff[i++], 1);
}
