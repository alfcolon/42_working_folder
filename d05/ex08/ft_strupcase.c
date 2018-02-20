int     ft_is_letter(char c, int only_upper, int only_lower)
{
    if (only_upper)
    {
        if ((c >= 'A') && (c <= 'Z'))
            return (1);
    }
    else if (only_lower)
    {
        if ((c >= 'a') && (c <= 'z'))
            return (1);
    }
    else if (!(only_upper) && !(only_lower))
    {
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
            return (1);
    }
    return (0);
}
char    *ft_strupcase(char *str)
{
    int     i;
    int     x;
    char    lwrcase;

    x = 32;
    i = 0;
    while (str[i])
    {
        lwrcase = ft_is_letter(str[i], 1, 0);
        if (lwrcase)
            str[i] &= ~x;
        i++;
    }
    return (str);
}
