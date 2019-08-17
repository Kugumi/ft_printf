/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:59:02 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/17 14:05:22 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_args
{
	unsigned long long	len;
	int					re;
	va_list				args;
}				t_args;

typedef struct	s_flags
{
	int					mi;
	int					pl;
	int					ze;
	int					oc;
	int					sp;
	int					width;
}				t_flags;

typedef struct	s_err
{
	int errf;
}				t_err;

t_args			ft_fillta(t_args *ag);
int				ft_printf(const char *restrict format, ...);
int				ft_flagsdi(const char *restrict fo, t_flags *fl);
int 			ft_flagscsp(const char *restrict fo, t_flags *fl);
int				ft_flagsf(const char *restrict fo, t_flags *fl);
int				ft_flagsu(const char *restrict fo, t_flags *fl);
int				ft_flagsoxX(const char *restrict fo, t_flags *fl);

#endif
