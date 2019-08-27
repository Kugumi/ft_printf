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

char  *ft_itoa_unsigned(long long int n)
{
  int                      i;
  unsigned long long int   nbr;
  char                      *t;

  i = ft_lennbr_base((unsigned long long int)n, 10);
  t = (char *)malloc(sizeof(char) * i + 1);
  if (t == NULL)
    return (0);
  if (n == -2147483648)
    return (ft_strcpy(t, "-2147483648"));
  t[i] = '\0';
  i--;
  nbr = (unsigned long long)n;
  while (i >= 0)
    {
      t[i] = (nbr % 10 + '0');
      nbr = (nbr / 10);
      i--;
    }
  return (t);
}
