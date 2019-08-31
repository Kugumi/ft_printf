/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:02:07 by kdeloise          #+#    #+#             */
/*   Updated: 2019/08/29 20:00:41 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_lennbr_base_ch(unsigned char n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_sh(unsigned short int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_ui(unsigned int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_ull(unsigned long long int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base(long long int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_ptr(intptr_t n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

char *ft_itoa_base(t_flags *fl, long long int n, int sz, char *base)
{
	int                     i;
	unsigned long long int  nbr;
	char                    *t;
	int                     x;
	int                     r;
	intptr_t				ptr;

	x = ft_strlen(base);
	i = (n > 0 && x == 10) ? ft_lennbr_base(n, x) : ft_lennbr_base(n, x);
	if (x == 8 || x == 16 || fl->unsign)
	{
		if (sz == 1)
			i = ft_lennbr_base_ch(n, x);
		else if (sz == 2)
			i = ft_lennbr_base_sh(n, x);
		else if (sz == 4)
			i = ft_lennbr_base_ui(n, x);
		else if (sz == 8)
			i = ft_lennbr_base_ull(n, x);
	}
	if (fl->isptr)
	{
		ptr = (intptr_t)&n;
		i = ft_lennbr_base_ptr(ptr, x) + 2;
	}
	if (n == 0 && (fl->xox == 1 || fl->xox == 3))
	    fl->oc = 0;
	if (!(fl->psn == 0 && n == 0))
	    fl->re += i;
	r = i;
    if (!fl->mi)
        ft_flag(fl, n, i);
	else
		ft_flagmi(fl, n, i);
	t = (char *)malloc(sizeof(char) * i + 1);
	if (t == NULL)
		return (0);
	if (n == -2147483648 && x == 10)
		return (ft_strcpy(t, "-2147483648"));
	t[i] = '\0';
	i--;
	nbr = (n < 0 && x == 10) ? (n * -1) : n;
	if (n < 0 && (x == 16 || x == 8 || fl->unsign)) 
		nbr = (unsigned long long int)n;
	while (i >= 0)
	{
		t[i] = base[nbr % x];
		nbr = nbr / x;
		i--;
	}
	if (fl->isptr)
	{
		t[0] = '0';
		t[1] = 'x';
	}
	if (!fl->nn)
		ft_putstr(t);
	if (fl->mi)
	{
        if (fl->wdh > r)
        {
        	if (!fl->nn)
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
