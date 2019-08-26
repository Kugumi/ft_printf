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
            else if (str[i] == '#' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
            {
                //str[i + 1] == 'x' ? ft_putstr("0x") : ft_putstr("0X");
                str[i + 1] == 'x' ? ft_putstr(ft_itoa_base(va_arg(ap, long long int), "0123456789abcdef")) :
                    ft_putstr(ft_itoa_base(va_arg(ap, long long int), "0123456789ABCDEF"));
                i++;
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
    int x;

    x = 34345;
    ft_printf("d = %d\ns = %s\nc = %c\nx = %#x\nX = %#X\n\n\n", x, "Hello", 'R', -255, 255);
    printf("d = %d\ns = %s\nc = %c\nx = %u\nX = %o\n", x, "Hello", 'R', -255, 255);
    return (0);
}