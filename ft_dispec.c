/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:30:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 07:36:20 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dispec(t_args *ag, t_flags *fl)
{
	if (!fl->lnh)
		return (ft_itoa_base(fl, va_arg(ag->args, int), 4, "0123456789"));
	else if (fl->lnh == 2)
		return (ft_itoa_base(fl, va_arg(ag->args, long long int), 8,
	"0123456789"));
	else if (fl->lnh == 1)
		return (ft_itoa_base(fl, va_arg(ag->args, long int), 8,
	"0123456789"));
	else if (fl->lnh == 4)
		return (ft_itoa_base(fl, (char)va_arg(ag->args, int), 2,
	"0123456789"));
	else if (fl->lnh == 3)
		return (ft_itoa_base(fl, (short)va_arg(ag->args, int), 1,
	"0123456789"));
		return (0);
}
