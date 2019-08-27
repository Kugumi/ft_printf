/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:04:46 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/20 19:04:47 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	len;
	char			*n;

	if (s1 && s2)
	{
		i = 0;
		len = ft_strlen(s1) + ft_strlen(s2);
		n = (char *)malloc(sizeof(char) * len + 1);
		if (n == NULL)
			return (NULL);
		while (*s1)
		{
			n[i] = *s1++;
			i++;
		}
		while (*s2)
			n[i++] = *s2++;
		n[i] = '\0';
		return (n);
	}
	return (0);
}
