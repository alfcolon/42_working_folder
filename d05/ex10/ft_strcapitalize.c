int     ft_is_space(char c)
{
    if (((c >= '\t') && (c <= '\r')) || (c == ' '))
        return (1);
    return (0);
}
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
int	ft_strlen(char *str)
{
    int	len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}
char    *ft_strcapitalize(char *str)
{
    int     len;
    int     lwrcase;
    int     spacechar;
    int     x;

    x = 32;
    len = ft_strlen(str) - 1;
    while (len >= 0)
    {
        lwrcase = ft_is_letter(str[len], 0, 1);
        spacechar = ft_is_space(str[len - 1]);
        if ((lwrcase) && (spacechar))
            str[len] &= ~x;
        len--;
    }
    return (str);
}
