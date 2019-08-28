/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 01:02:00 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/29 01:23:35 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_procspec(t_flags *fl)
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
