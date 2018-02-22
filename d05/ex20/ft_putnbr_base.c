#include <unistd.h>
char    const octals[9] = {'0','1','2','3','4','5','6','7'};
char    const binary[3] = {'0','1'};
char    const base10[11] = {'0','1','2','3','4','5','6','7','8','9'};
char    const base16[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void     ft_convert_base(int nbr, int base)
{
    char    numarr[50];
    int     count;

    count = 0;
    while (nbr > 0)
    {
        numarr[count] = base16[nbr % base];
        nbr /= base;
        count++;
    }
    while (--count >= 0)
    {
        ft_putchar(numarr[count]);
    }
}

int     ft_lsearch(char key, char const *base, int size)
{
    int     i;

    if (size == 16)
    {
        if ((key >= 'a') && (key <= 'z'))
            key -= 32;
    }
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
        ft_convert_base(nbr, len);
    }
}
int     main()
{
    char    base[17] = {'0','1','2','3','4','5','6','7','8','9','a','B','C','d','E','F'};
    ft_putnbr_base(282, base);

    return 0;
}