#include "ft_printf.h"

t_flags ft_filltf(t_flags *fl)
{
	fl->re = 0;
	fl->len = 2;
	fl->re = 0;
	fl->mi = 0;
	fl->pl = 0;
	fl->ze = 0;
	fl->oc = 0;
	return (*fl);
}
