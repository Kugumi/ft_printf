/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:43:30 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/20 18:43:31 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*n;

	if (s)
	{
		i = 0;
		j = 0;
		n = (char *)malloc(sizeof(char) * len + 1);
		if (n == 0)
			return (0);
		while (i < start)
			i++;
		while (s[i] != '\0' && j < len)
			n[j++] = s[i++];
		n[j] = '\0';
		return (n);
	}
	return (0);
}
