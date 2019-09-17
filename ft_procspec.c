/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 01:02:00 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/30 04:35:48 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_procspec(t_flags *fl)
{
	if (!fl->mi)
	{
		ft_flag(fl, 1, 1);
		write(1, "%", 1);
		fl->re += 1;
	}
	else
	{
		ft_flagmi(fl, 1, 1);
		write(1, "%", 1);
		fl->re += 1;
	}
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
}

void	ft_flagstr(t_flags *fl, char *str)
{
	char	*buff;
	char 	*tmp;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	buff = (char *)malloc(sizeof(char));
	buff[i] = '\0';
	if (fl->psn > 0)
	{
			buff = ft_strsub(str, 0, fl->psn);
			fl->wdh -= (int)(j = ft_strlen(buff));
			fl->re += (int)j;
	}
	else if (fl->psn == -1)
    {
	    tmp = ft_strjoin(buff, str);
		free(buff);
		buff = tmp;
	    fl->wdh -= (int)(j = ft_strlen(buff));
	    fl->re += (int)j;
    }
	if (fl->wdh > 0)
	{
		//fl->wdh -= j;
		while (fl->wdh)
		{
			tmp = ft_strjoin(" ", buff);
			free(buff);
			buff = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	while (buff[i] != '\0')
		write(1, &buff[i++], 1);
	free(buff);
}

int	ft_flagstrmi(t_flags *fl, char *str)
{
	int i;
	int psn1;

	psn1 = fl->psn;
	i = 0;
	if (fl->mi)
	{
		if (psn1 > 0)
		{
			while (psn1 && str[i])
			{
				write(1, &str[i], 1);
				psn1 -= 1;
				fl->wdh -= 1;
				fl->re += 1;
				i++;
			}
		}
        else if (psn1 == -1)
        {
            while (str[i])
            {
                write(1, &str[i], 1);
                fl->wdh -= 1;
                fl->re += 1;
                i++;
            }
        }
	}
	return (i);
}
