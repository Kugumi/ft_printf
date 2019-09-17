#include "ft_printf.h"

int     lennbrf(double x)
{
    int     i;

    i = 0;
    if (x < 0)
    {
        i++;
        x = x * -1.0;
    }
    while(x >= 1)
    {
        x = x / 10.0;
        i++;
    }
    return (i);
}

char    *ft_dtoa(t_flags *fl, long double x, int p)
{
    int             c;
    double          ap;
    unsigned long   bp;
    char            *str;
    int             i, t, isnull;

    if (x != x)
    {
        if (!(str = (char *)malloc(sizeof(char) * 3 + 1)))
            return (NULL);
        return ("nan");
    }
    if ((x == x + x / .0) && x > 0)
    {
        if (!(str = (char *)malloc(sizeof(char) * 3 + 1)))
            return (NULL);
        if (fl->pl)
            return ("+inf");
        else
            return ("inf");
    }
    if ((x == x + x / .0) && x < 0)
    {
        if (!(str = (char *)malloc(sizeof(char) * 4 + 1)))
            return (NULL);
        return ("-inf");
    }
    if ((x == x + x / .0) && x > 0)
    isnull = 0;
    c = lennbrf(x);
    if (x > -1 && x < 1)
    {
        c = 1;
        isnull = 1;
    }
    if (x < 0)
        x = x * -1.0;
    bp = (unsigned long)x;
    ap = x - bp;
    if (p < 0)
        p = 6;
    if (p > 0)
    {   
        if (!(str = (char *)malloc(sizeof(char) * (c + p + 2))))
            return (NULL);
    }
    else
    {   
        if (!(str = (char *)malloc(sizeof(char) * (c + 2))))
            return (NULL);
    }
    t = c;
    i = p;
    if (p > 0)
    {
        str[t++] = '.';
        while(p > 0)
        {
            ap = ap * 10.0;
            str[t++] = (char)ap + '0';
            ap = ap - (char)ap;
            p--;
        }
        str[t--] = '\0';
        if (str[t] == '9' && str[t - 1] == '9')
        {
            while(str[t] == '9')
            {
                str[t] = '0';
                t--;
            }
            // str[t] = str[t] + 1;
        }
        if (ap >= 0.5)
            str[t] = str[t] + 1;
    }
    else
        str[c] = '\0';
    c--;
    if (ap >= 0.5 && i == 0)
    {
        str[c] = (bp % 10) + '0' + 1;
        bp = bp / 10;
        c--;
    }
    while (c >= 0)
    {
        str[c] = (bp % 10) + '0';
        bp = bp / 10;
        c--;
    }
    if (str[0] == '0' && !isnull)
        str[0] = '-';
    if (!fl->mi)
        ft_fflag(fl, str);
    ft_putstr(str);
    return (str);
}

// int main()
// {
//     float x;
//     char *str;

//     x = 1.79769e+19;
//     //x = x + x / .0;
//     str = ft_dtoa(x, 7);
//     printf("%s\n", str);
// //    printf("%.100f\n", x);
//     printf("%.7lf\n", x);
//     return (0);
// }