#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_flags
{
	unsigned long long len;
	int re;
	va_list args;
}	t_flags;

t_flags ft_filltf(t_flags *fl);
int ft_printf(const char * restrict format, ...);
