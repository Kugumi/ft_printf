/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:11:07 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/26 19:02:58 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_flags(const char *restrict fo, t_flags *fl, unsigned long long l)
{
	if (fo[l - 3] == 'l' || fo[l - 3] == 'h' || fo[l - 3] == 'L')
	{
		if (fo[l - 3] == 'L')
		{
			if (fo[l - 2] == 'f')
			{
				fl->lnh = 5;
				return (ft_flagsf(fo, fl));
			}
			else
				return (-1);
		}
        if (!(l - 3 == 0))
        {
            if (fo[l - 4] == 'l' || fo[l - 4] == 'h')
            {
                if (fo[l - 4] == 'l' && fo[l - 3] == 'l')
                {
					fl->lnh = 2;
                    if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
                        return (ft_flagsdi(fo, fl));
                    if (fo[l - 2] == 'u')
                        return (ft_flagsu(fo, fl));
                    if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                        return (ft_flagsoxX(fo, fl));
                    else
                        return (-1);
                }
                if (fo[l - 4] == 'h' && fo[l - 3] == 'h')
                {
					fl->lnh = 4;
                    if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
                        return (ft_flagsdi(fo, fl));
                    if (fo[l - 2] == 'u')
                        return (ft_flagsu(fo, fl));
                    if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                        return (ft_flagsoxX(fo, fl));
                    else
                        return (-1);
                }
                return (-1);
            }
        }
        if (fo[l - 3] == 'h')
        {
			fl->lnh = 3;
            if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
                return (ft_flagsdi(fo, fl));
            if (fo[l - 2] == 'u')
                return (ft_flagsu(fo, fl));
            if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                return (ft_flagsoxX(fo, fl));
            else
                return (-1);
        }
        if (fo[l - 3] == 'l')
        {
			fl->lnh = 1;
            if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
                return (ft_flagsdi(fo, fl));
            if (fo[l - 2] == 'u')
                return (ft_flagsu(fo, fl));
            if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                return (ft_flagsoxX(fo, fl));
            if (fo[l - 2] == 'f')
                return (ft_flagsf(fo, fl));
            else
                return (-1);
        }
	}
	if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
		return (ft_flagsdi(fo, fl));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxX(fo, fl));
	if (fo[l - 2] == 'f')
		return (ft_flagsf(fo, fl));
	if (fo[l - 2] == 'c' || fo[l - 2] == 's' || fo[l - 2] == 'p')
		return (ft_flagscsp(fo, fl, l));
	return (-1);
}

void	ft_dispec(t_args *ag, const char *restrict fo)
{
	int l;

	l = va_arg(ag->args, int);
	ag->re += ft_putstr(ft_itoa(l));
}

int ft_spec(const char * restrict fo, t_args *ag, t_flags *fl)
{
	int f;

	f = 1;
	if (fo[f] == '%')
		return (0);
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'p' && fo[f] != 'o' && fo[f] != 'u' && fo[f] != 'x' && fo[f] !=
				'X' && fo[f] != 'f' && fo[f] != 's' && fo[f] != '\0')
	{
		ag->len += 1;
		f++;
	}
	f = 1;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'p' && fo[f] != 'o' && fo[f] != 'u' && fo[f] != 'x' && fo[f] !=
				'X' && fo[f] != 'f' && fo[f] != 's' && fo[f] != '\0')
	{
			if (ft_flags(fo + f, fl, ag->len) == -1)
				return (-1);
			f += (ag->len - 2);
	}
	if (fo[f] == 'd' || fo[f] == 'i')
		ft_dispec(ag, fo + f);
	if (fo[f] == 'c')
		ft_cspec(ag, fo + f);
	return (1);
}

int	ft_printf(const char *restrict format, ...)
{
	t_args	ag;
	t_err	err;
	t_flags	fl;
	int		f;

	ag = ft_fillta(&ag);
	fl = ft_filltf(&fl);
	va_start(ag.args, format);
	f = 0;
	while (format[f])
	{
		while (format[f] == '%')
		{
			if ((err.errf = ft_spec(format + f, &ag, &fl)) == 0)
			{
				write(1, "%", 1);
				ag.re += 1;
				f += 2;
			}
			else if (err.errf == -1)
			{
				write(1, "Wrong flag with this conversion specifier\n", 42);
				return (0);
			}
			else
				f += ag.len;
		}
		if (!format[f])
			break ;
		write(1, &format[f], 1);
		ag.re += 1;
		f++;
	}
	va_end(ag.args);
	return (ag.re);
}

int main(void)
{
	int d = 92233720;
	char c = 'h';
	int d1 = 0;
//
//	ft_printf("%%%-+++++++++++++++---------------0000000          100.lld", d);
//	printf("%d - %u\n", -2147483648, -2147483648);
}
