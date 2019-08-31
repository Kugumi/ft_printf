/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:38:30 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/29 20:10:14 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_flagmi(t_flags *fl, long long int num, int r)
{
	if (fl->mi)
	{
		if (fl->pl)
		{
			if (num >= 0)
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
		else if (fl->sp && num >= 0)
		{
			write(1, " ", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
		if (num < 0 && !fl->pl && !fl->isxox && !fl->unsign)
		{
			write(1, "-", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
        if (num == 0 && fl->psn == 0)
            fl->nn = 1;
		if (fl->oc)
			ft_octmi(fl);
		if (fl->psn > 0)
		{
			if (r < fl->psn)
			{
				fl->psn -= r;
				while(fl->psn)
				{
					write(1, "0", 1);
					fl->psn -= 1;
					fl->wdh -= 1;
					fl->re += 1;
				}
			}
		}
/*  	if (fl->wdh > r)
		{
			fl->wdh -= r;
			while (fl->wdh)
			{
				write(1, " ", 1);
				fl->wdh -= 1;
				fl->re += 1;
			}
		}*/
	}
}

void ft_flag(t_flags *fl, long long int num, int r)
{
	char *buff;
	int i;

	i = 0;
	buff = (char *)malloc(sizeof(char));
	buff[i] = '\0';
	if (fl->pl)
	{
		if (num >= 0)
		{
			buff = ft_strjoin(buff, "+");
			fl->wdh -= 1;
			fl->re += 1;
		}
		else
		{
			buff = ft_strjoin(buff, "-");
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	else if (fl->sp && num >= 0)
	{
		buff = ft_strjoin(buff, " ");
		fl->wdh -= 1;
		fl->re += 1;
	}
	if (num < 0 && !fl->pl && !fl->isxox && !fl->unsign)
	{
		buff = ft_strjoin(buff, "-");
		fl->wdh -= 1;
		fl->re += 1;
	}
	if (num == 0 && fl->psn == 0)
	    fl->nn = 1;
	if (fl->oc)
		ft_oct(fl, &buff);
	if (fl->psn > 0)
	{
		if (r < fl->psn)
		{
		    fl->psn -= r;
			while (fl->psn)
			{
				buff = ft_strjoin(buff, "0");
				fl->psn -= 1;
				fl->wdh -= 1;
				fl->re += 1;
			}
		}
	}
	if (fl->wdh > r)
	{
        if (!fl->nn)
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
