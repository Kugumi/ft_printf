#include "ft_printf.h"

void	ft_fflag(t_flags *fl, char *s, int num)
{
	char *buff;
	char *tmp;
	int i;
	int r;

	r = (int)ft_strlen(s);
	fl->re += r;
	i = 0;
	buff = (char *)malloc(sizeof(char));
	buff[i] = '\0';
	if (fl->pl)
	{
		if (!num)
		{
			tmp = ft_strjoin(buff, "+");
			free(buff);
			buff = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
        else
        {
            tmp = ft_strjoin(buff, "-");
            free(buff);
            buff = tmp;
            fl->wdh -= 1;
            fl->re += 1;
        }
	}
	else if (fl->sp && !num)
	{
		tmp = ft_strjoin(buff, " ");
        free(buff);
        buff = tmp;
		fl->wdh -= 1;
		fl->re += 1;
	}
    if (num && !fl->pl)
    {
        tmp = ft_strjoin(buff, "-");
        free(buff);
        buff = tmp;
        fl->wdh -= 1;
        fl->re += 1;
    }
	if (fl->wdh > r)
	{
		fl->wdh -= r;
		while (fl->wdh)
		{
			if (fl->ze)
			{
                tmp = ft_strjoin(buff, "0");
                free(buff);
                buff = tmp;
            }
			else
            {
                tmp = ft_strjoin(" ", buff);
                free(buff);
                buff = tmp;
            }
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	while(buff[i] != '\0')
		write(1, &buff[i++], 1);
	free(buff);
}

void ft_fflagmi(t_flags *fl, char *s, int num)
{
    fl->re += (int)ft_strlen(s);
    if (fl->mi)
    {
        if (fl->pl)
        {
            if (!num)
            {
                write(1, "+", 1);
                fl->wdh -= 1;
                fl->re += 1;
            }
            else
            {
                write(1, "-", 1);
                fl->wdh -= 1;
                fl->re += 1;
            }
        }
        else if (fl->sp && !num)
        {
            write(1, " ", 1);
            fl->wdh -= 1;
            fl->re += 1;
        }
        if (num && !fl->pl)
        {
            write(1, "-", 1);
            fl->wdh -= 1;
            fl->re += 1;
        }
    }
}

