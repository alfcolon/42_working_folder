void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int    ft_lsearch(char letter, int k, int j)
{
    char    arr[34] = {'0','a','b','e','f','n','r','t','v','1','2','3','4','5','6','e','f','0','1','2','3','4','5','6','7','8','9','a','c','d','e','f','f'};
    char    hexas[34][3] = {"00","07","08","1b","0c","0a","0d","09","0b","01","02","03","04","05","06","0e","0f","10","11","12","13","14","15","16","17","18","19","1a","1c","1d","1e","1f","7f"};
    int     i;

    i = k;
    while (i <= j)
    {
        if (letter == arr[i])
        {
            ft_putchar(hexas[i][0]);
            ft_putchar(hexas[i][1]);
            return (3);
        }
        i++;
    }
    return (0);
}
int   ft_is_printable(char letters[3], int idx)
{
    if (letters[0] == 'x')
    {
        if (letters[1] == '7')
            return (ft_lsearch(letters[2], 32, 32));
        if (letters[1] == '0')
            return (ft_lsearch(letters[2], 9, 16));
        if (letters[1] == '1')
            return (ft_lsearch(letters[2], 17, 31));
    }
    return (ft_lsearch(letters[0], 0, 8)); //tells i to skip 2 places
}
void    ft_putstr_non_printable(char *str)
{
    char    letters[4];
    char    printable;
    int     idx;
    int     i;

    idx = 0;
    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        if (str[i] == '\\')
        {
            letters[0] = str[i + 1];
            letters[1] = str[i + 2];
            letters[2] = str[i + 3];
            printable = ft_is_printable(letters, idx);
            if (printable)
                i += printable;
        }
        i++;
    }
}
