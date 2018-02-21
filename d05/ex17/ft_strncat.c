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
char    *ft_strncat(char *dest, char *src, int nb)
{
    int     destlen;
    int     i;

    destlen = ft_strlen(dest);

    i = 0;
    while (i < nb)
    {
        dest[destlen] = src[i];
        i++;
        destlen++;
    }
    return (dest);
}
