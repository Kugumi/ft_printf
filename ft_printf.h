/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:59:02 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/05 21:46:14 by jijerde          ###   ########.fr       */
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
	int					psn;  //precision
	int					lnh;  //length
	int					unsign; // for u
	int                 re;   //return value
	int					nn;   // 0 with 0 psn
	int					xox;  // 1 - x 2 - o 3 - X
	int                 isxox; // xox or not
	int					isptr; // for %p
}				t_flags;

typedef struct	s_err
{
	int errf;
}				t_err;

void            ft_flag(t_flags *fl, long long int num, int r);
void            ft_flagstr(t_flags *fl, char *str);
void            ft_flagmi(t_flags *fl, long long int num, int r);
int				ft_flagstrmi(t_flags *fl, char *str);
int				ft_lennbr_base_ull(unsigned long long int n, int x);
char 			*ft_itoa_base(t_flags *fl, long long int n, int sz, char *base);
void			ft_cspec(t_args *ag, t_flags *fl);
char			*ft_pspec(t_args *ag, t_flags *fl);
void            ft_sspec(t_args *ag, t_flags *fl);
char    		*ft_uspec(t_args *ag, t_flags *fl);
char            *ft_xoXspec(t_args *ag, t_flags *fl, const char * restrict fo);
void			ft_procspec(t_flags *fl);
int				ft_psn(const char *restrict fo, t_flags *fl, t_args *ag);
void			ft_wdh(const char *restrict fo, t_flags *fl, t_args *ag);
void            ft_oct(t_flags *fl, char **buff);
void            ft_octmi(t_flags *fl);
t_args			ft_fillta(t_args *ag);
t_flags			ft_filltf(t_flags *fl);
int				ft_printf(const char *restrict format, ...);
int				ft_flagsproc(const char *restrict fo, t_flags *fl, t_args *ag);
int				ft_flagsdi(const char *restrict fo, t_flags *fl, t_args *ag);
int 			ft_flagscsp(const char *restrict fo, t_flags *fl,
		unsigned long long l, t_args *ag);
int				ft_flagsf(const char *restrict fo, t_flags *fl, t_args *ag);
int				ft_flagsu(const char *restrict fo, t_flags *fl, t_args *ag);
int				ft_flagsoxX(const char *restrict fo, t_flags *fl, t_args *ag);
int             ft_color(const char *restrict fo);
void            ft_rspec(t_args *ag, t_flags *fl);
char    		*ft_dtoa(t_flags *fl, long double x, int p);
char    		*ft_fspec(t_args *ag, t_flags *fl);

#endif
