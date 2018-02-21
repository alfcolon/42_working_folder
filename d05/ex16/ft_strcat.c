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
char    *ft_strcat(char *dest, char *src)
{
    int     destlen;
    int     srclen;
    int     i;

    destlen = ft_strlen(dest);
    srclen = ft_strlen(src);
    
    i = 0;
    while (i <= srclen)
    {
        dest[destlen] = src[i];
        i++;
        destlen++;
    }
    return (dest);
}
