/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:50:22 by kdeloise          #+#    #+#             */
/*   Updated: 2019/08/19 17:50:29 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int spec(char c)
{
    if (c == 's' || c == 'c' || c == 'd' || c == 'i')
        return (1);
    else
        return (0);
}

void ft_printf(char *str, ...)
{
    int i;
    va_list ap;

    va_start(ap, str);
    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
                ft_putstr(va_arg(ap, char *));
            else if (str[i] == 'c')
                ft_putchar((char)(va_arg(ap, int)));
            else if (str[i] == 'd' || str[i] == 'i')
                ft_putstr(ft_itoa(va_arg(ap, long int)));
            else if (str[i] == 'l' && str[i + 1] == 'l' && str[i + 2] == 'u')
            {
                ft_putstr(ft_itoa_unsigned((va_arg(ap, unsigned long long int))));
                i += 2;
            }
            else if (str[i] == 'x' || str[i] == 'X')
            {
                //str[i + 1] == 'x' ? ft_putstr("0x") : ft_putstr("0X");
                str[i + 1] == 'x' ? ft_putstr(ft_itoa_base(va_arg(ap, long long int), "0123456789abcdef")) :
                    ft_putstr(ft_itoa_base(va_arg(ap, long long int), "0123456789ABCDEF"));
            }
            else if (str[i] == 'o')
            {
                //str[i + 1] == 'x' ? ft_putstr(ft_itoa_base(va_arg(ap, long long int), "01234567")) :
                ft_putstr(ft_itoa_base(va_arg(ap, unsigned int), "01234567"));
            }
        }
        else
            ft_putchar(str[i]);
        i++;
    }
    va_end(ap);
}

int     main(int arg, char **argv)
{
    int x = -255;
    unsigned long long int ll = -255;
    
    ft_printf("d = %d\ns = %s\nc = %c\nx = %x\nX = %X\no = %o\nll = %llu\n\n", x, "Hello", 'R', -255, -255, 255, ll);
       printf("d = %d\ns = %s\nc = %c\nx = %x\nX = %X\no = %o\nll = %llu\n\n", x, "Hello", 'R', -255, -255, 255, ll);
    printf("%020d|", 100);
    return (0);
}