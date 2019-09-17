#include "ft_printf.h"

int     lennbrf(double x)
{
    int     i;

    i = 0;
    if (x < 0)
        x = x * -1.0;
    while(x >= 1)
    {
        x = x / 10.0;
        i++;
    }
    return (i);
}

char    *ft_dtoa(t_flags *fl, long double x, int p)
{
    int                  c;
    long double          ap;
    unsigned long long   bp;
    char                *str;
    int                 i, t, isnull, mn, okr;

    okr = 0;
    mn = 0;
    if (x != x)
    {
        write(1, "nan", 3);
        return ("nan");
    }
    if ((x == x + x / .0) && x > 0)
    {
        if (fl->pl)
        {
            write(1, "+inf", 4);
            return ("+inf");
        }
        else
        {
            write(1, "inf", 3);
            return ("inf");
        }
    }
    if ((x == x + x / .0) && x < 0)
        return ("-inf");
    if ((x == x + x / .0) && x > 0)
    isnull = 0;
    c = 0;
//    if (x < 0)
//        c++;
    c = c + lennbrf(x);
    if (x > -1 && x < 1)
    {
        c++;
        isnull = 1;
    }
    if (x < 0)
    {
        x = x * -1.0;
        mn = 1;
    }
    bp = (unsigned long long)x;
    ap = x - bp;
    if (p < 0)
        p = 6;
    if (p > 0)
    {   
        if (!(str = (char *)malloc(sizeof(char) * (c + p + 2))))
            return (NULL);
    }
    else if (p == 0)
    {   
        if (!(str = (char *)malloc(sizeof(char) * (c + 2))))
            return (NULL);
    }
//    printf("%d\n\n", c);
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
        if (str[t] == '9' && ap >= 0.5)
        {
            while(str[t] == '9')
            {
                str[t] = '0';
                t--;
                if(str[t] == '.')
                    okr = 1;
            }
            // str[t] = str[t] + 1;
        }
        if (ap >= 0.5 && str[t] != '.')
            str[t] = str[t] + 1;
    }
    else
        str[c] = '\0';
    c--;
    if ((ap >= 0.5 && i == 0) || okr == 1)
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
//    if (str[0] == '0' && mn)
//        str[0] = '-';
    if (!fl->mi)
        ft_fflag(fl, str, mn);
    else
        ft_fflagmi(fl, str, mn);
    ft_putstr(str);
    if (fl->oc && fl->psn == 0)
    {
        write(1, ".", 1);
        fl->re += 1;
        fl->wdh -= 1;
    }
    if (fl->mi)
    {
        if (fl->wdh > (int)ft_strlen(str))
        {
            fl->wdh -= (int)ft_strlen(str);
            while (fl->wdh)
            {
                write(1, " ", 1);
                fl->wdh -= 1;
                fl->re += 1;
            }
        }
    }
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