/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rspec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 02:52:56 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/10 04:50:27 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rpz(char *b, t_flags *fl)
{
	int i;

	i = 0;
	while (b[i] != '\0')
	{
		while (b[i] == '\t' || b[i] == '\n' || b[i] == '\v' || b[i] == '\f'
				|| b[i] == '\r')
		{
			write(1, "\\", 1);
			if (b[i] == '\t')
				write(1, "t", 1);
			else if (b[i] == '\n')
				write(1, "n", 1);
			else if (b[i] == '\v')
				write(1, "v", 1);
			else if (b[i] == '\f')
				write(1, "f", 1);
			else if (b[i] == '\r')
				write(1, "r", 1);
			i++;
			fl->wdh -= 2;
			fl->re += 2;
		}
		if (b[i] == '\0')
			break;
		write(1, &b[i++], 1);
	}
}

void	ft_rp(int psn1, char *b, t_flags *fl)
{
	int i;

	i = 0;
	while (b[i] != '\0' && psn1)
	{
		while ((b[i] == '\t' || b[i] == '\n' || b[i] == '\v' || b[i] == '\f'
				|| b[i] == '\r') && psn1 > 0)
		{
			write(1, "\\", 1);
			if (b[i] == '\t')
				write(1, "t", 1);
			else if (b[i] == '\n')
				write(1, "n", 1);
			else if (b[i] == '\v')
				write(1, "v", 1);
			else if (b[i] == '\f')
				write(1, "f", 1);
			else if (b[i] == '\r')
				write(1, "r", 1);
			i++;
			psn1 -= 2;
			fl->wdh -= 2;
			fl->re += 2;
		}
		if (b[i] == '\0' || !(psn1 > 0))
			break;
		write(1, &b[i++], 1);
	}
}

int	ft_flagstrmir(t_flags *fl, char *str)
{
	int i;
	int psn1;

	psn1 = fl->psn;
	i = 0;
	if (fl->mi)
	{
		if (psn1 > 0)
			ft_rp(psn1, str, fl);
        else if (psn1 == -1)
			ft_rpz(str, fl);
	}
	return (i);
}

void	ft_flagstrr(t_flags *fl, char *str)
{
	char	*b;
	char 	*tmp;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	b = (char *)malloc(sizeof(char));
	b[i] = '\0';
	if (fl->psn > 0)
	{
			b = ft_strsub(str, 0, fl->psn);
			fl->wdh -= (int)(j = ft_strlen(b));
			fl->re += (int)j;
	}
	else if (fl->psn == -1)
    {
	    tmp = ft_strjoin(b, str);
		free(b);
		b = tmp;
	    fl->wdh -= (int)(j = ft_strlen(b));
	    fl->re += (int)j;
    }
	if (fl->wdh > 0)
	{
		//fl->wdh -= j;
		while (fl->wdh)
		{
			tmp = ft_strjoin(" ", b);
			free(b);
			b = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	while (b[i] != '\0')
	{
		while (b[i] == '\t' || b[i] == '\n' || b[i] == '\v' || b[i] == '\f'
				|| b[i] == '\r')
		{
			write(1, "\\", 1);
			if (b[i] == '\t')
				write(1, "t", 1);
			else if (b[i] == '\n')
				write(1, "n", 1);
			else if (b[i] == '\v')
				write(1, "v", 1);
			else if (b[i] == '\f')
				write(1, "f", 1);
			else if (b[i] == '\r')
				write(1, "r", 1);
			i++;
		}
		if (b[i] == '\0')
			break;
		write(1, &b[i++], 1);
	}
	free(b);
}

void	ft_rspec(t_args *ag, t_flags *fl)
{
	char *str;
	int s;

	str = va_arg(ag->args, char *);
	if (str == NULL)
		str = "(null)";
	if (!fl->mi)
		ft_flagstrr(fl, str);
	else
		s = ft_flagstrmir(fl, str);
	if (fl->mi)
	{
	    if (fl->psn == -1)
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
