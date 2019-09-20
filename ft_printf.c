/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:11:07 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 09:37:00 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	if (!(l - 2 == 0))
		if (fo[l - 2] == '%')
			return (ft_flagsproc(fo, fl, ag));
	if (fo[l - 3] == 'l' || fo[l - 3] == 'h' || fo[l - 3] == 'L')
	{
		if ((ft_pricont5(fo, fl, l, ag) == -1))
			return (-1);
		else
			return (0);
	}
	if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
		return (ft_flagsdi(fo, fl, ag));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl, ag));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxx(fo, fl, ag));
	if (fo[l - 2] == 'f')
		return (ft_flagsf(fo, fl, ag));
	if (fo[l - 2] == 'c' || fo[l - 2] == 's' || fo[l - 2] == 'p' || fo[l - 2] == 'r')
		return (ft_flagscsp(fo, fl, ag));
	return (-1);
}

int	ft_spec(const char *fo, t_args *ag, t_flags *fl)
{
	int f;

	if (fo[1] == '%')
		return (0);
	if ((f = ft_spec2(fo, ag, fl)) == -1)
		return (-1);
	ft_spec3(fo, ag, fl, f);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_args	ag;
	t_flags	fl;
	int		f;
	int		c;

	va_start(ag.args, format);
	f = 0;
	fl.re = 0;
	while (format[f])
	{
		while (format[f] == '{')
		{
            ((c = ft_color(format + f)) != 0) ? f += c : 0;
			if (c == 0)
				break ;
		}
		while (format[f] == '%')
			if ((f = ft_printf2(format + f, &fl, &ag, f)) == 0)
				return (0);
		if (!format[f])
			break ;
		write(1, &format[f++], 1);
		fl.re += 1;
	}
	va_end(ag.args);
	return (fl.re);
}
/*  int main(void)
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
	   	printf ("hello, %s.", "gavin");
        printf("\n");
    	ft_printf ("hello, %s.", "gavin");
// 	// printf ("%llu, %llu, %u, %d\n", ll, -42, -42, -10);
// 	// ft_printf ("%100.2s", NULL);
// 	// ft_printf ("%llu, %llu, %u, %d\n", ll, -42, -42, -10);
// 	// printf("%p\n", 0);
// 	// ft_printf("%p", 0);
 //    ft_printf("%0#100.10o", 123);
//     // printf("priv");
//  	// printf("%f", d);
 //	 printf("%#-x", 20126);
 //	 printf("\n");
 //	 ft_printf("%#-x %% %#d %d", 20126, 31, 31);
    //printf("\n");
   //ft_printf("%10.10s", "priv");
// 	// printf("\n\n\n\n");

// 	printf ("%.5p", 0);
// 	printf ("\n");
//    ft_printf ("%.5p", 0);
   return (0);
}*/