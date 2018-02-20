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

char    *ft_str_is_alpha(char *str)
{
    int     i;
    int     isletter;

    i = 0;
    while (str[i])
    {
        isletter = ft_is_letter(str[i], 0, 0);
        if (!(isletter))
            return (0);
        i++;
    }
    return (1);
}
