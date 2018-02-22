#include <stdio.h>
#include <unistd.h>
char    const binary[3] = {'0','1'};
char    const octals[9] = {'0','1','2','3','4','5','6','7'};
char    const base10[11] = {'0','1','2','3','4','5','6','7','8','9'};
char    const base16[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//int     ft_get_nbr(char nbr, int start, int end, int base)
//{
//    int     sign;
//
//    sign = 1;
//    if (nbr[start - 1] == '-')
//        sign *= -1;
//    while (nbr > 0)
//    {
//        nbr /= base;
//    }
//    //DIFFERENT CASES FOR DIFF BASE SYSTEM CONVERSIONS, OY
//}
int	    ft_strlen(char *str)
{
    int	    len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    if (len <= 1)
        return (0);
    return (len);
}
int     ft_dupes(char *str)
{
    int     i;
    int     j;

    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j] < '\0')
        {
            if (str[i] == str[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int     ft_is_hexa(char *base)
{
    int     i;

    i = 0;
    while (base[i])
    {
        if ((base[i] >= 'a') && (base[i] <= 'f'))
                return (1);
        else if ((base[i] >= 'A') && (base[i] <= 'F'))
            return (1);
        i++;
    }
    return (0);
}
int     ft_is_base10(char *base)
{
    int     i;

    i = 0;
    while (base[i])
    {
        if ((base[i] >= '8') && (base[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}
int     ft_is_octal(char *base)
{
    int     i;

    i = 0;
    while (base[i])
    {
        if ((base[i] >= '2') && (base[i] <= '7'))
            return (1);
        i++;
    }
    return (0);
}
int     ft_is_binary(char *base)
{
    int     i;

    i = 0;
    while (base[i])
    {
        if ((base[i] < '0') || (base[i] > '1'))
            return (0);
        i++;
    }
    return (1);
}
//have to edit for that 0a => 0 case
int     ft_get_base(char *base)
{
    int     i;

    if (ft_is_hexa(base))
        return (16);
    else if (ft_is_base10(base))
        return (10);
    else if (ft_is_octal(base))
        return (8);
    else if (ft_is_binary(base))
        return (2);
    return (0);
}
int	    ft_atoi_base_start(char *str)
{
    int     i;

    i = 0;
    while ((str[i] >= 9 && str[i] <= 16) || str[i] == 32)
    {
        i++;
    }
    if ((str[i] == '-') || (str[i] == '+'))
    {
        i++;
    }
    if (((str[i] >= 'A') && (str[i] <= 'F')) || ((str[i] >= 'a') && (str[i] <= 'f')))
        return (i);
    else if ((str[i] >= '0') && (str[i] <= '9'))
        return (i);
    else
        return (-1);
}
int	    ft_atoi_base_end(char *str, int start, int base)
{
    int     end;

    end = start;
    while (str[end])
    {
        if ((str[end] >= '0') && (str[end] <= '9'))
            end++;
        else if ((str[end] >= 'a') && (str[end] <= 'f'))
            end++;
        else if ((str[end] >= 'A') && (str[end] <= 'F'))
            end++;
    }
    return (end);
}
int     ft_atoi_base(char *str, char *base)
{
    int     start;
    int     end;
    int     nb;
    int     valid_base;

    valid_base  = ft_get_base(base);
    if ((!(ft_strlen(base)) || !(ft_dupes(base)) || !(valid_base)))
        return (0);
    start = ft_atoi_base_start(str);
    end = ft_atoi_base_end(str, start, valid_base);
    printf("str: %s\nbase: %s\nstart: %d\nend: %d\nvalidbase: %d\n", str, base, start, end, valid_base);
//DIFFERENT CASES FOR DIFF BASE SYSTEM CONVERSIONS, OY
//    if ((start > -1) && (end > -1))
//        nb = ft_get_nbr(str, start, end, valid_base);
    return (nb);
}
int     main()
{
    char    base[17] = {'0','1','2','3','4','5','6','7','8','9','A','b','c','d','e','f'};
    ft_atoi_base("_3f_", base);
    return 0;
}