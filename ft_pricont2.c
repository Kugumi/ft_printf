/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pricont2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:01:23 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 07:25:54 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pricont6(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	int t;

	if (fo[l - 3] == 'L')
	{
		if (fo[l - 2] == 'f')
		{
			fl->lnh = 5;
			return (ft_flagsf(fo, fl, ag));
		}
		else
			return (-1);
	}
	if (!(l - 3 == 0))
	{
		if ((t = ft_pricont(fo, fl, l, ag)) == -1)
			return (-1);
		else if (t == 3)
			;
		else if (t == 0)
			return (0);
	}
	return (3);
}
