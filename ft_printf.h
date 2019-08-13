/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:59:02 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/13 05:18:55 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	unsigned long long	len;
	int					re;
	int					mi;
	int					pl;
	int					ze;
	int					oc;
	int					sp;
	va_list				args;
}				t_flags;

typedef struct	s_err
{
	int errf;
}				t_err;

t_flags			ft_filltf(t_flags *fl);
int				ft_printf(const char *restrict format, ...);

#endif
