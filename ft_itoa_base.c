/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:02:07 by kdeloise          #+#    #+#             */
/*   Updated: 2019/08/28 06:37:53 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_lennbr_base(long long int n, int x)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

char *ft_itoa_base(t_flags *fl, long long int n, char *base)
{
	int                     i;
	unsigned long long int  nbr;
	char                    *t;
	int                     x;
	int                     r;

	x = ft_strlen(base);
	i = (n > 0) ? ft_lennbr_base(n, x) : ft_lennbr_base(n, x) + 1;
	fl->re += i;
	r = i;
    if (!fl->mi)
        ft_flag(fl, n, i);
	else
		ft_flagmi(fl, n, i);
	t = (char *)malloc(sizeof(char) * i + 1);
	if (t == NULL)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(t, "-2147483648"));
	t[i] = '\0';
	i--;
	nbr = (n < 0 && (x == 16 || x == 8)) ? (unsigned long long int)n : n;
	nbr = (n < 0 && x == 10) ? (n * -1) : n; 
	while (i >= 0)
	{
		t[i] = base[nbr % x];
		nbr = nbr / x;
		i--;
	}
	// if (n < 0 && x == 10)
	// 	t[0] = '-';
	if (n < 0 && x == 10)
		ft_putstr(t + 1);
	else
		ft_putstr(t);
	if (fl->mi)
	{
        if (fl->wdh > r)
        {
            fl->wdh -= r;
            while (fl->wdh)
            {
                write(1, " ", 1);
                fl->wdh -= 1;
                fl->re += 1;
            }
        }
    }
	return (t);
}
