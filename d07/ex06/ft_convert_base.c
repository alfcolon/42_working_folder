#include <stdlib.h>

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
char    *ft_strrev(char *str, int len)
{
    int     i;
    char    temp;

    i = 0;
    while (i <= --len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
    }
    return (str);
}

int	    ft_iterative_power(int nbr, int power)
{
    int		total;

    if (nbr <= 0)
        return (0);
    else if (power == 0)
        return (1);
    total = 1;
    while (power > 0)
    {
        total *= nbr;
        power--;
    }
    return (total);
}
char    ft_get_base_val(int nbr)
{
    if (nbr > 9)
        return (nbr - 10 + 'a');
    else
        return (nbr + '0');
}
int     *ft_from_base10(char *arr, int nbr, int base_to) //there's probs some iterative way o get length of converted nbr
{
    int     i;
    int     sign;

    sign = 1;
    i = 0;
    if (nbr < 0)
    {
        nbr *= -1;
        sign *= -1;
    }
    while (nbr > 0)
    {
        arr[i] = ft_get_base_val(nbr % base_to);
        nbr /= base_to;
        i++;
    }
    if (sign == -1)
        arr[i++] = '-';
    arr[i] = '\0';
    ft_strrev(arr, i);
    printf("%s\n", arr);
    return (arr);
}
int     ft_to_base10(char *nbr, int base_from, int len)
{
    unsigned int 	total;
    int 	offset;
    int 	power;
    int 	num;
    int 	sign;

    sign = 1;
    total = 0;
    power = 0;
    offset = 0;
    if ((nbr[0] == '-') || (nbr[0] == '+'))
        offset++;
    if (nbr[0] == '-')
        sign *= - 1;
    while (--len >= offset)
    {
        if (nbr[len] > '9')//for base 16
            num = (nbr[len] - 'a') + 10;
        num = (nbr[len] - '0');
        total += num * ft_iterative_power(base_from, power++);
    }
    if (sign == -1 && total < -2147483648)
        return (0);
    if (total <= 2147483647)
        return (total * sign);
    return (0);
}

int     ft_lsearch(char *str, char key)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] == key)
            return (1);
        i++;
    }
    return (0);
}
int     ft_validbase(char *str)
{
    int     i;
    int     base;
    char    base_chars[17] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    base = 0;
    i = 0;
    if ((str[0] == '+') || (str[0] == '-')) //for nbr str with + or -
        i = 1;
    while (i < 17)
    {
        if (!ft_lsearch(base_chars, str[i]))
            break;
        base += 1;
        i++;
    }
    if (base == 2 || base == 8 || base == 10 || base == 16)//assuming bases will all chars are passed in
        return (base);
    return (0);
}
char    *ft_strlowcase(char *str)
{
    int     i;
    int     x;

    x = 32;
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'F')
            str[i] |= x;
        i++;
    }
    return (str);
}
char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int     validbase_nbr;
    int     validbase_from;
    int     validbase_to;
    int     base10;
    char    *arr = (char *)malloc(sizeof(arr) * 100);

    ft_strlowcase(nbr); //make sure all strings are in low case in case base16
    ft_strlowcase(base_from);
    ft_strlowcase(base_to);
    validbase_from = ft_validbase(base_from);
    validbase_to = ft_validbase(base_to);
    validbase_nbr = ft_validbase(nbr); //get strs' base numbers
    if (validbase_from && validbase_to)//make sure passed bases are legit
        if (validbase_nbr <= validbase_from) {
            base10 = ft_to_base10(nbr, validbase_from, ft_strlen(nbr));
            return (ft_from_base10(arr, base10, validbase_to));
        }
    return ("0");
}
