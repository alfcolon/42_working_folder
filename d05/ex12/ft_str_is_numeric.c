int     ft_is_digit(char c)
{
    if ((c >= '0') && (c <= '9'))
        return (1);
    return (0);
}

char    *ft_str_is_numeric(char *str)
{
    int     i;
    int     isnumeric;

    i = 0;
    while (str[i])
    {
        isnumeric = ft_is_digit(str[i]);
        if (!(isnumeric))
            return (0);
        i++;
    }
    return (1);
}
