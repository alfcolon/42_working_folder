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
int unsigned    ft_strlcat(char *dest, char *src, unsigned int size)
{
    /*appends src to dst. Will append at most dstsize - strlen(dst) - 1 chars.
    dstsize should be exact, overlap is undefined behavior and, append a null after cat'ing src if dstsize != 0*/
    int     destlen;
    int     i;
    int     end;
    unsigned int     newdestsize;

    destlen = ft_strlen(dest);
    end = size - destlen - 1;
    i = 0;
    while (i < end)
    {
        dest[destlen] =  src[i];
        destlen++;
        i++;
    }
    if ((size > 0) && (destlen < size))
        dest[size - 1] = '\0';
    newdestsize = --i + destlen;
    return (newdestsize);

}
