/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:59:56 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 04:14:41 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_xoxspec(t_args *ag, t_flags *fl, const char *fo)
{
	fl->isxox = 1;
	if (fo[0] == 'x')
		fl->xox = 1;
	else if (fo[0] == 'o')
		fl->xox = 2;
	else if (fo[0] == 'X')
		fl->xox = 3;

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

void ft_oct(t_flags *fl, char **buff, char *tmp)
{
	if (fl->xox == 1)
    {
		tmp = ft_strjoin("0x", *buff);
		free(*buff);
		*buff = tmp;
		fl->wdh -= 2;
		fl->re += 2;
	}
    else if (fl->xox == 2)
	{
    	tmp = ft_strjoin("0", *buff);
		free(*buff);
		*buff = tmp;
    	fl->wdh -= 1;
    	fl->re += 1;
	}
    else if (fl->xox == 3)
	{
    	tmp = ft_strjoin("0X", *buff);
		free(*buff);
		*buff = tmp;
    	fl->wdh -= 2;
    	fl->re += 2;
	}
}

void ft_octmi(t_flags *fl)
{
	if (fl->xox == 1)
	{
		write(1, "0x", 2);
		fl->wdh -= 2;
		fl->re += 2;
	}
	else if (fl->xox == 2)
	{
		write(1, "0", 1);
		fl->wdh -= 1;
		fl->re += 1;
	}
	else if (fl->xox == 3)
	{
		write(1, "0X", 2);
		fl->wdh -= 2;
		fl->re += 2;
	}
}