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
unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    /*copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.*/
    int     i;
    int     end;

    end = size - 1;
    printf("size: %d\n", size);
    i = 0;
    while (i < end)
    {
        dest[i] =  src[i];
        i++;
    }
    if (size > 0)
        dest[size - 1] = '\0';
    return (i + 1);

}
