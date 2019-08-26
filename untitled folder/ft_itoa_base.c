/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:02:07 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/22 23:02:08 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lennbr_base(unsigned long long int n, int x)
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


char *ft_itoa_base(long long int n, char *base)
{
  int                     i;
  unsigned long long int  nbr;
  char                    *t;
  int                     x;

  x = ft_strlen(base);
  i = (n > 0) ? ft_lennbr_base(n, x) : ft_lennbr_base((unsigned long long int )n, x) + 1;
  t = (char *)malloc(sizeof(char) * i + 1);
  if (t == NULL)
    return (0);
  if (n == -2147483648)
    return (ft_strcpy(t, "-2147483648"));
  t[i] = '\0';
  i--;
  nbr = (n < 0) ? (unsigned long long int)n : n;
  while (i >= 0)
  {
    t[i] = base[nbr % x];
    nbr = nbr / x;
    i--;
  }
  if (n < 0 && x == 16)
  {
    t[0] = 'f';
    printf("||");
  }
  else if (n < 0 && x == 8)
  {
    t[0] = '0';
    printf("||");
  }
  else if (n < 0 && x == 10)
  {
    t[0] = '-';
    printf("||");
  }
  return (t);
}
