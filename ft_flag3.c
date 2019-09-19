/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:34:43 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/19 03:48:07 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag4(char **buff, t_flags *fl, int r)
{
	char *tmp;

	if (r < fl->psn)
	{
		fl->psn -= r;
		while (fl->psn)
		{
			tmp = ft_strjoin(*buff, "0");
			free(*buff);
			*buff = tmp;
			fl->psn -= 1;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}

void	ft_flag5(char **buff, t_flags *fl)
{
	char *tmp;

	tmp = ft_strjoin(*buff, "-");
	free(*buff);
	*buff = tmp;
	fl->wdh -= 1;
	fl->re += 1;
}
