/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 04:57:26 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/17 12:37:08 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				c;
	long int		res;

	i = 0;
	res = 0;
	c = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		c = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res < 0 && c == 1)
			return (-1);
		else if (res < 0 && c == -1)
			return (0);
	}
	return (res * c);
}
