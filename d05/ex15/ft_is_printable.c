int     ft_is_printable(char c)
{
    if (c <= 32) 
        return (1);
    return (0);
}

char    *ft_str_is_alpha(char *str)
{
    int     i;
    int     printable;

    i = 0;
    while (str[i])
    {
        printable = ft_is_printable(str[i]);
        if (!(printable))
            return (0);
        i++;
    }
    return (1);
}
