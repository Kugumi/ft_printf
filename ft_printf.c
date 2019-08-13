/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:11:07 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/13 06:11:52 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flags(const char *restrict fo, t_flags *fl)
{
	int f;

	while (fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'l' && fo[f] != 'h'
			&& fo[f] != '.' && !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
			fl->mi = 1;
		else if (fo[f] == '+')
		{
			if ((fl->pl = 1) && !(fl->sp = 0))
				;
		}
		else if (fo[f] == ' ')
		{
			if (!(fl->pl))
				fl->sp = 1;
		}
		else if (fo[f] == '0')
			fl->ze = 1;
		else
			return (-1);
		f++;
	}
	return (1);
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
				'X' || format[f] != 'f' || fo[f] != 'l' || fo[f] != 'h' || format[f] != 'L'*/)
	{
		fl->len += 1;
		f++;
	}
	f = 1;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' /*  || format[f] != 'p' || format[f] != 'o' || format[f] != 'u' || format[f] != 'x' || format[f] !=
				'X' || format[f] != 'f' || fo[f] != 'l' || fo[f] != 'h' || format[f] != 'L'*/)
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

	ft_printf("hey %% %+++00+-+ ---00   0+0-d", d);
}
