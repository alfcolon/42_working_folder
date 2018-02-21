#include <stdio.h>
char    octal[9] = {'p','o','n','e','y','v','i','f'};
char    binary[3] = {'0','1'};
char    base10[11] = {'0','1','2','3','4','5','6','7','8','9'};
char    base16[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
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
    char     *basesys;
    
    
    i = 0;
    while(i < size)
    {
        if ((size == 8) && (!(ft_lsearch(base[i], octal, size))))
            return (0);
        i++;
    }
    return (1);
}
int	    ft_strlen(char *str)
{
    int	len;

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
    if ((len == 2) || (len == 8) || (len == 10) || (len == 16))
    {
        if (ft_is_base(base, len))
        {
            printf("it works: base:%s\nnbr:%d\n", base, nbr);
        }
    }
}
int     main()
{
    char    *octal = "poneyvif";
    ft_putnbr_base(44, octal);

    return 0;
}
