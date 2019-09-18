/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:21:17 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/18 08:33:25 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flagsdi2(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'l' && fo[f] != 'h'
			&& fo[f] != '.' && !(fo[f] >= 49 && fo[f] <= 57) && fo[f] != '*')
	{
		if (fo[f] == '-')
		{
			if (!(fl->ze = 0))
				fl->mi = 1;
		}
		else if (fo[f] == '+')
		{
			if (!(fl->sp = 0))
				fl->pl = 1;
		}
		else if (fo[f] == ' ')
		{
			if (!(fl->pl))
				fl->sp = 1;
		}
		else if (fo[f] == '0')
		{
			if (!(fl->mi))
				fl->ze = 1;
		}
		else
			return (-1);
		f++;
	}
	return (f);
}
