/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:11:07 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/15 22:10:27 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flags(const char *restrict fo, t_flags *fl)
{
	if (fo[0] == 'l' || fo[0] == 'h' || fo[0] == 'L')
	{
		if (fo[0] == 'L')
		{
			if (fo[1] == 'f')
				return (ft_flagsf(fo, fl));
			else
				return (-1);
		}
		if (fo[0] == 'l' || fo[0] == 'h')
		{
			if (fo[0] == 'l' && fo[1] == 'l')
			{
				if ((fo[2] == 'd' || fo[2] == 'i'))
					return (ft_flagsdi(fo, fl));
				if (fo[2] == 'u')
					return (ft_flagsu(fo, fl));
				if (fo[2] == 'o' || fo[2] == 'x' || fo[2] == 'X')
					return (ft_flagsoxX(fo, fl));
				else
					return (-1);
			}
			if (fo[0] == 'h' && fo[1] == 'h')
			{
				if ((fo[2] == 'd' || fo[2] == 'i'))
					return (ft_flagsdi(fo, fl));
				if (fo[2] == 'u')
					return (ft_flagsu(fo, fl));
				if (fo[2] == 'o' || fo[2] == 'x' || fo[2] == 'X')
					return (ft_flagsoxX(fo, fl));
				else
					return (-1);
			}
			if (fo[0] == 'h')
			{
				if (fo[1] == 'd' || fo[1] == 'i')
					return (ft_flagsdi(fo, fl));
				if (fo[1] == 'u')
					return (ft_flagsu(fo, fl));
				if (fo[1] == 'o' || fo[1] == 'x' || fo[1] == 'X')
					return (ft_flagsoxX(fo, fl));
				else
					return (-1);
			}
			if (fo[0] == 'l')
			{
				if (fo[1] == 'd' || fo[1] == 'i')
					return (ft_flagsdi(fo, fl));
				if (fo[1] == 'u')
					return (ft_flagsu(fo, fl));
				if (fo[1] == 'o' || fo[1] == 'x' || fo[1] == 'X')
					return (ft_flagsoxX(fo, fl));
				if (fo[1] == 'f')
					return (ft_flagsf(fo, fl));
				else
					return (-1);
			}
		}
	}
	if (fo[0] == 'd' || fo[0] == 'i')
		return (ft_flagsdi(fo, fl));
	if (fo[0] == 'u')
		return (ft_flagsu(fo, fl));
	if (fo[0] == 'o' || fo[0] == 'x' || fo[0] == 'X')
		return (ft_flagsoxX(fo, fl));
	if (fo[0] == 'f')
		return (ft_flagsf(fo, fl));
	if (fo[0] == 'c' || fo[0] == 's' || fo[0] == 'p')
		return (ft_flagscsp(fo, fl));
	return (-1);
}

void	ft_dispec(t_flags *fl, const char *restrict fo)
{
	int l;

	l = va_arg(fl->args, int);
	fl->re += ft_putstr(ft_itoa(l));
}

int ft_spec(const char * restrict fo, t_flags *fl)
{
	int f;

	f = 1;
	if (fo[f] == '%')
		return (0);
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' /*|| format[f] != 'p' || format[f] != 'o' || format[f] != 'u' || format[f] != 'x' || format[f] !=
				'X' || format[f] != 'f'*/)
	{
		fl->len += 1;
		f++;
	}
	f = 1;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i'/*  || format[f] != 'p' || format[f] != 'o' || format[f] != 'u' || format[f] != 'x' || format[f] !=
				'X' || format[f] != 'f'*/)
	{
			if (ft_flags(fo + f, fl) == -1)
				return (-1);
			f += (fl->len - 2);
	}
	if (fo[f] == 'd' || fo[f] == 'i')
		ft_dispec(fl, fo + f);
	return (1);
}

int	ft_printf(const char *restrict format, ...)
{
	t_flags	fl;
	t_err	err;
	int		f;

	fl = ft_filltf(&fl);
	va_start(fl.args, format);
	f = 0;
	while (format[f])
	{
		while (format[f] == '%')
		{
			if ((err.errf = ft_spec(format + f, &fl)) == 0)
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
				f += fl.len;
		}
		if (!format[f])
			break ;
		write(1, &format[f], 1);
		fl.re += 1;
		f++;
	}
	va_end(fl.args);
	return (fl.re);
}

int main(void)
{
	int d = 127;
	int d1 = 0;

	ft_printf("%lc", d);
}
