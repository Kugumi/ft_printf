#include "ft_printf.h"
#include <stdio.h>

int		ft_lennbr_base_ch(unsigned char n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_sh(unsigned short int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_ui(unsigned int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base_ull(unsigned long long int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}

int		ft_lennbr_base(long long int n, int x)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / x;
		len++;
	}
	return (len);
}