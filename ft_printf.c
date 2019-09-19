/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:11:07 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/05 21:42:41 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
int ft_flags(const char *restrict fo, t_flags *fl, unsigned long long l, t_args *ag)
{
    if (!(l - 2 == 0))
        if (fo[l - 2] == '%')
            return (ft_flagsproc(fo, fl, ag));
    if (fo[l - 3] == 'l' || fo[l - 3] == 'h' || fo[l - 3] == 'L')
	{
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
            if (fo[l - 4] == 'l' || fo[l - 4] == 'h')
            {
                if (fo[l - 4] == 'l' && fo[l - 3] == 'l')
                {
					fl->lnh = 2;
                    if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
                        return (ft_flagsdi(fo, fl, ag));
                    if (fo[l - 2] == 'u')
                        return (ft_flagsu(fo, fl, ag));
                    if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                        return (ft_flagsoxX(fo, fl, ag));
                    else
                        return (-1);
                }
                if (fo[l - 4] == 'h' && fo[l - 3] == 'h')
                {
					fl->lnh = 4;
                    if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
                        return (ft_flagsdi(fo, fl, ag));
                    if (fo[l - 2] == 'u')
                        return (ft_flagsu(fo, fl, ag));
                    if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                        return (ft_flagsoxX(fo, fl, ag));
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
                return (ft_flagsdi(fo, fl, ag));
            if (fo[l - 2] == 'u')
                return (ft_flagsu(fo, fl, ag));
            if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                return (ft_flagsoxX(fo, fl, ag));
            else
                return (-1);
        }
        if (fo[l - 3] == 'l')
        {
			fl->lnh = 1;
            if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
                return (ft_flagsdi(fo, fl, ag));
            if (fo[l - 2] == 'u')
                return (ft_flagsu(fo, fl, ag));
            if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
                return (ft_flagsoxX(fo, fl, ag));
            if (fo[l - 2] == 'f')
                return (ft_flagsf(fo, fl, ag));
            else
                return (-1);
        }
	}
	if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
		return (ft_flagsdi(fo, fl, ag));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl, ag));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxX(fo, fl, ag));
	if (fo[l - 2] == 'f')
		return (ft_flagsf(fo, fl, ag));
	if (fo[l - 2] == 'c' || fo[l - 2] == 's' || fo[l - 2] == 'p' || fo[l - 2] == 'r')
		return (ft_flagscsp(fo, fl, ag));
	return (-1);
}

char	*ft_dispec(t_args *ag, t_flags *fl)
{
	if (!fl->lnh)
		return (ft_itoa_base(fl, va_arg(ag->args, int), 4, "0123456789"));
	else if (fl->lnh == 2)
		return (ft_itoa_base(fl, va_arg(ag->args, long long int), 8, "0123456789"));
	else if (fl->lnh == 1)
		return (ft_itoa_base(fl, va_arg(ag->args, long int), 8, "0123456789"));
	else if (fl->lnh == 4)
		return (ft_itoa_base(fl, (char)va_arg(ag->args, int), 2, "0123456789"));
	else if (fl->lnh == 3)
		return (ft_itoa_base(fl, (short)va_arg(ag->args, int), 1, "0123456789"));
//	fl->re += ft_putstr(ft_itoa(l));
	return (0);
}

int ft_spec(const char * restrict fo, t_args *ag, t_flags *fl)
{
	int f;

	f = 1;
	if (fo[f] == '%')
		return (0);
	ag->len = 2;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'p' && fo[f] != 'o' && fo[f] != 'u' && fo[f] != 'x' && fo[f] !=
				'X' && fo[f] != 'f' && fo[f] != 's' && fo[f] != '\0' && fo[f] != '%' && fo[f] != 'r')
	{
		ag->len += 1;
		f++;
	}
	f = 1;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'p' && fo[f] != 'o' && fo[f] != 'u' && fo[f] != 'x' && fo[f] !=
				'X' && fo[f] != 'f' && fo[f] != 's' && fo[f] != '\0' && fo[f] != '%' && fo[f] != 'r')
	{
			if (ft_flags(fo + f, fl, ag->len, ag) == -1)
				return (-1);
			f += (ag->len - 2);
	}
	if (fo[f] == 'd' || fo[f] == 'i')
		ft_dispec(ag, fl);
	else if (fo[f] == 'u')
		ft_uspec(ag, fl);
	else if (fo[f] == 'p')
		ft_pspec(ag, fl);
	else if (fo[f] == 'x' || fo[f] == 'X' || fo[f] == 'o')
		ft_xoXspec(ag, fl, fo + f);
	else if (fo[f] == 'c')
		ft_cspec(ag, fl);
	else if (fo[f] == 'f')
		ft_fspec(ag, fl);
	else if (fo[f] == '%')
	    ft_procspec(fl);
	else if (fo[f] == 's')
		ft_sspec(ag, fl);
	else if (fo[f] == 'r')
		ft_rspec(ag, fl);
	else if (fo[f - 1] == '%')
	    ag->len -= 1;
	return (1);
}

int	ft_printf(const char *restrict format, ...)
{
	t_args	ag;
	t_err	err;
	t_flags	fl;
	int		f;
	int 	c;

	va_start(ag.args, format);
	f = 0;
	fl.re = 0;
	while (format[f])
	{
		while (format[f] == '{')
		{
            if ((c = ft_color(format + f)) != 0)
                f += c;
            if (c == 0)
                break;
        }
		while (format[f] == '%')
		{
			fl = ft_filltf(&fl);
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
	return (fl.re);
}

/* int main(void)
 {
//  	double d = 92233720;
// 	d = d + d / .0;
// 	// char c = 'h';
// 	// char *s = "priv!";
// 	// static long int ll = -42;
// 	// int ll = 32767;
// 	// long int l = 92;

// 	// ft_printf("%5%");
// 	// write(1, "\n", 1);
// 	// printf("\n%d", printf("%5%"));
//    printf ("%s\n", "priv");
 //   ft_printf ("%s\n", "priv");
// 	// printf ("%llu, %llu, %u, %d\n", ll, -42, -42, -10);
// 	// ft_printf ("%100.2s", NULL);
// 	// ft_printf ("%llu, %llu, %u, %d\n", ll, -42, -42, -10);
// 	// printf("%p\n", 0);
// 	// ft_printf("%p", 0);
//     // ft_printf("%-.2r\n", "\n\n\t\f");
//     // printf("priv");
//  	// printf("%f", d);
//  	// printf("%Lf", -56.2012685l);
// 	// printf("\n");
    printf("% 0+-#%");
    printf("\n");
    ft_printf("% 0+-#%");
// 	// printf("\n\n\n\n");

// 	printf ("%.5p", 0);
// 	printf ("\n");
//    ft_printf ("%.5p", 0);
   return (0);
}*/