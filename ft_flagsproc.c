/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsproc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:47:04 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/29 00:58:44 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagsproc(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != '%' && fo[f] != '.' && !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
			fl->mi = !(fl->ze = 0) ? 1 : 1;
		else if (fo[f] == '+' || fo[f] == ' ' || fo[f] == '#')
			;
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else
			return (-1);
		f++;
	}
	if (fo[f] >= 48 && fo[f] <= 57)
	{
		ft_wdh(fo + f, fl);
		while (fo[f] >= 48 && fo[f] <= 57)
			f++;
	}
	if (fo[f] == '.')
	{
		ft_psn(fo + f, fl);
		f++;
		while (fo[f] >= 48 && fo[f] <= 57)
			f++;
	}
	if (fo[f] != '%')
		return (-1);
	return (1);
}