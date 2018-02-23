<<<<<<< HEAD
int     i;
int     j;

int	ft_iterative_power(int nb, int power)
=======
#include <stdio.h>
char    const octals[9] = {'0','1','2','3','4','5','6','7'};
char    const binary[3] = {'0','1'};
char    const base10[11] = {'0','1','2','3','4','5','6','7','8','9'};
char    const base16[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int     ft_lsearch(char key, char const *base, int size)
>>>>>>> 8df9da15f355336599594be8553714e55256e977
{
    int		total;

<<<<<<< HEAD
    if (nb <= 0)
        return (0);
    else if (power == 0)
        return (1);
    total = 1;
    while (power > 0)
=======
    if (size == 16)
    {
        if ((key >= 'a') && (key <= 'z'))
            key -= 32;
    }
    i = 0;
    while (i < size)
>>>>>>> 8df9da15f355336599594be8553714e55256e977
    {
        total *= nb;
        power--;
    }
    return (total);
}
int     ft_base10(char *str, int base, int size)
{
<<<<<<< HEAD
    int 	total;
    int 	sign;
    int 	power;
    int 	num;
    int 	l;

    l = 0;
    total = 0;
    sign = 1;
    power = 0;
    if (str[0] == '-')
    {
        sign *= -1;
        ++l;
    }
    while (size >= l)
    {
        if (str[size] > '9')
            num = (str[size] - 'a') + 10;
        else
            num = (str[size] - '0');
        total += num * ft_iterative_power(base, power);
        power++;
        size--;
    }
    return (total * sign);
}
int     ft_isdecimal(char c)
{
    if ((c >= '0') && (c <= '1'))
        return (2);
    if ((c >= '2') && (c <= '7'))
        return (8);
    if ((c >= '8') && (c <= '9'))
        return (10);
    if ((c >= 'a') && (c <= 'f'))
        return (16);
    if ((c >= 'A') && (c <= 'F'))
        return (16);
    return (0);
}
int	    ft_get_atoi_base(char *str)
{
    int     base;
    int     base_n;
    int     k;
=======
    int     i;
    char    const *basesys;

    if (size == 2)
        basesys = binary;
    else if (size == 8)
        basesys = octals;
    else if (size == 10)
        basesys = base10;
    else if (size == 16)
        basesys = base16;
    else
        return (0);
>>>>>>> 8df9da15f355336599594be8553714e55256e977

    base = 0;
    k = 0;
    while (((str[k] >= 9) && (str[k] <= 13)) || (str[k] == 32))
    {
        k++;
    }
    i = k;
    if ((str[k] == '-') || (str[k] == '+'))
    {
        k++;
    }
    base_n = ft_isdecimal(str[k]);
    while (str[k] != '\0')
    {
        if (base < base_n)
            base = base_n;
        base_n = ft_isdecimal(str[++k]);
    }
    j = k;
    return base;
}
int	    ft_strlen(char *str)
{
    int	    len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}
int     ft_valid_char(char *str)
{
    char    valid_chars[17] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int     i;
    int     j;

    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (valid_chars[j])
        {
            if (str[i] == valid_chars[j])
                break;
            if ((j == 15) && (str[i] != valid_chars[j]))
                return (0);
            j++;
        }
        i++;
    }
}
int     ft_dupes(char *str)
{
    int     k;
    int     l;

    k = 0;
    while (str[k])
    {
        l = k + 1;
        while (str[j])
        {
            if (str[k] == str[l])
                return (0);
            l++;
        }
        k++;
    }
    return (1);
}
int	ft_atoi_base10(char *dest, char *src, int str_base)
{
<<<<<<< HEAD
    int     start;
    int     k;
    int     atoi;
    int     size;

    k = 0;
    start = i;
    while(start < j)
    {
        dest[k] = src[start];
        k++;
        start++;
    }
    dest[k] = '\0';
    size = ft_strlen(dest);
    atoi = ft_base10(dest, str_base, --size);
    return (atoi);
}
int     ft_atoi_base(char *str, char *base)
{
    char    temp[50];
    int     base_base;
    int     str_base;
    int     str_atoi;
    int     len;

    base_base  = ft_get_atoi_base(base);
    len = ft_strlen(base);
    if ((len < 2) || !(ft_dupes(base)) || !(base_base) || !(ft_valid_char(base)))
        return (0);
    str_base = ft_get_atoi_base(str);
    if (str_base < base_base)
        str_base = base_base;
    str_atoi = ft_atoi_base10(temp, str, str_base);
    return (str_atoi);
=======
    char    base[17] = {'0','1','2','3','4','5','6','7','8','9','a','B','C','d','E','F'};
    ft_putnbr_base(44, base);

    return 0;
>>>>>>> 8df9da15f355336599594be8553714e55256e977
}
