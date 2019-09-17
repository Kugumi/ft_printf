#include "ft_printf.h"

char    *ft_fspec(t_args *ag, t_flags *fl)
{
    if (!fl->lnh)
        return (ft_dtoa(fl, va_arg(ag->args, double), fl->psn));
    else if (fl->lnh == 1)
        return (ft_dtoa(fl, va_arg(ag->args, double), fl->psn));
    else if (fl->lnh == 5)
        return (ft_dtoa(fl, va_arg(ag->args, long double), fl->psn));
    return(0);
}
