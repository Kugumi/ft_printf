/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 01:27:32 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 01:27:37 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nbr;
	int					negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	(str[i] == '-') ? negative *= -1 : negative;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	if (nbr > 9223372036854775807)
	{
		return (negative < 0) ? 0 : -1;
	}
	return ((int)nbr * negative);
}
