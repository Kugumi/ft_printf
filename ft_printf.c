/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:11:07 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/27 18:25:12 by jijerde          ###   ########.fr       */
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

size_t	ft_dispec(t_args *ag, t_flags *fl, const char *restrict fo)
{
	/*if (!fl->lnh)
		return (ft_itoa(p, va_arg(ag->args, int)));
	else */if (fl->lnh == 2)
		return (ft_itoa_base(fl, va_arg(ag->args, long long int), "0123456789"));
	/*else if (fl->lnh == 1)
		return (ft_itoa(p, va_arg(ag->args, long int)));
	else if (fl->lnh == 4)
		return (ft_itoa(p, (char)va_arg(ag->args, unsigned int)));
	else if (fl->lnh == 3)
		return (ft_itoa(p, (short)va_arg(ag->args, int)));*/
//	fl->re += ft_putstr(ft_itoa(l));
}	

int ft_spec(const char * restrict fo, t_args *ag, t_flags *fl)
{
	int f;

	f = 1;
	if (fo[f] == '%')
		return (0);
	ag->len = 2;
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
		ft_dispec(ag, fl, fo + f);
	if (fo[f] == 'c')
		ft_cspec(ag, fl, fo + f);
	return (1);
}

int	ft_printf(const char *restrict format, ...)
{
	t_args	ag;
	t_err	err;
	t_flags	fl;
	int		f;

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
				fl.re += 1;
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
		fl.re += 1;
		f++;
	}
	va_end(ag.args);
	printf("\n%d\n", fl.re);
	return (fl.re);
}

int main(void)
{
	int d = -92233720;
	char c = 'h';
	int d1 = 0;
	long long int ll = -15;
	long int l = 9223372036854775808;

	ft_printf("%020.lld", l);
	write(1, "\n", 1);
	printf("\n%d", printf("%020.lld", l));
	return (0);
}
