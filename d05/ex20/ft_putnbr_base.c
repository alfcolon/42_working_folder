#include <stdio.h>
char    const octal[9] = {'0','1','2','3','4','5','6','7'};
char    const binary[3] = {'0','1'};
char    const base10[11] = {'0','1','2','3','4','5','6','7','8','9'};
char    const base16[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int     ft_lsearch(char key, char *base, int size)
{
    int     i;

    i = 0;
    while (i < size)
    {
        if (key == base[i])
            return (1);
        i++;
    }
    return (0);
}
int     ft_is_base(char *base, int size)
{
    int     i;
    char    *basesys;

    if (size == 2)
        basesys = binary;
    else if (size == 8)
        basesys = octal;
    else if (size == 10)
        basesys = base10;
    else if (size == 16)
        basesys = base16;
    else
        return (0);

    i = 0;
    while (i < size)
    {
        if (!(ft_lsearch(base[i], basesys, size)))
            return (0);
        i++;
    }
    return (1);
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
void    ft_putnbr_base(int nbr, char *base)
{
    int     len;

    len = ft_strlen(base);
    if (ft_is_base(base, len))
    {
        printf("it works: base:%s\nnbr:%d\n", base, nbr);
    }
}
int     main()
{
    char    base[9] = {'0','1','2','3','4','5','6','7'};
    ft_putnbr_base(44, octal);

    return 0;
}
