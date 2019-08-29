/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:59:02 by jijerde           #+#    #+#             */
/*   Updated: 2019/08/29 18:38:20 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>

typedef struct	s_args
{
	unsigned long long	len;
	va_list				args;
}				t_args;

typedef struct	s_flags
{
	int					mi;   //минус
	int					pl;   //plus
	int					ze;   //zero
	int					oc;   //#
	int					sp;   // ' '
	int					wdh;  //width
	int					psn;  //persision
	int					lnh;  //lengh
	int					sign; // ??
	int                 re;   //return value
}				t_flags;

typedef struct	s_err
{
	int errf;
}				t_err;

void            ft_flag(t_flags *fl, long long int num, int r);
void            ft_flagmi(t_flags *fl, long long int num, int r);
char            *ft_itoa_base(t_flags *fl, long long int n, char *base);
void			ft_cspec(t_args *ag, t_flags *fl);
void			ft_procspec(t_flags *fl);
int				ft_psn(const char *restrict fo, t_flags *fl);
void			ft_wdh(const char *restrict fo, t_flags *fl);
t_args			ft_fillta(t_args *ag);
t_flags			ft_filltf(t_flags *fl);
int				ft_printf(const char *restrict format, ...);
int				ft_flagsproc(const char *restrict fo, t_flags *fl);
int				ft_flagsdi(const char *restrict fo, t_flags *fl);
int 			ft_flagscsp(const char *restrict fo, t_flags *fl,
		unsigned long long l);
int				ft_flagsf(const char *restrict fo, t_flags *fl);
int				ft_flagsu(const char *restrict fo, t_flags *fl);
int				ft_flagsoxX(const char *restrict fo, t_flags *fl);

#endif
