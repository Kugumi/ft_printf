/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:59:56 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/30 20:23:06 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_xoXspec(t_args *ag, t_flags *fl, const char * restrict fo)
{
	fl->xox = 1;

	if (!fl->lnh)
	{
		if (fo[0] == 'x')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned int), 4, "0123456789abcdef"));
		else if (fo[0] == 'o')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned int), 4, "01234567"));
		else if (fo[0] == 'X')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned int), 4, "0123456789ABCDEF"));
	}
	else if (fl->lnh == 2)
	{
		if (fo[0] == 'x')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int), 8, "0123456789abcdef"));
		else if (fo[0] == 'o')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int), 8, "01234567"));
		else if (fo[0] == 'X')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int), 8, "0123456789ABCDEF"));
	}
	else if (fl->lnh == 1)
	{
		if (fo[0] == 'x')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int), 8, "0123456789abcdef"));
		else if (fo[0] == 'o')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int), 8, "01234567"));
		else if (fo[0] == 'X')
			return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int), 8, "0123456789ABCDEF"));
	}
	else if (fl->lnh == 4)
	{
		if (fo[0] == 'x')
			return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int), 1, "0123456789abcdef"));
		else if (fo[0] == 'o')
			return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int), 1, "01234567"));
		else if (fo[0] == 'X')
			return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int), 1, "0123456789ABCDEF"));
	}
	else if (fl->lnh == 3)
	{
		if (fo[0] == 'x')
			return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int), 2, "0123456789abcdef"));
		else if (fo[0] == 'o')
			return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int), 2, "01234567"));
		else if (fo[0] == 'X')
			return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int), 2, "0123456789ABCDEF"));
	}
	return (0);
}
