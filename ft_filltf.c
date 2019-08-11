#include "ft_printf.h"

t_flags ft_filltf(t_flags *fl)
{
	fl->re = 0;
	fl->len = 2;
	return (*fl);
}
