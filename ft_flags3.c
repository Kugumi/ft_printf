/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:13:10 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 02:17:48 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagsoxx2(const char *restrict fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'o' && fo[f] != 'x' && fo[f] != 'X' && fo[f] != '.'
			&& fo[f] != 'l' && fo[f] != 'h' && !(fo[f] >= 49 && fo[f] <= 57)
			&& fo[f] != '*')
	{
		if (fo[f] == '-')
		{
			if (!(fl->ze = 0))
				fl->mi = 1;
		}
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else if (fo[f] == '#')
			fl->oc = 1;
		else
			return (-1);
		f++;
	}
	return (f);
}
