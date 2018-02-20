char    *ft_strncpy(char *dest, char *src, int n)
{
    while (!(n < 1) && (*dest++ = *src++))
    {
        n--;
    }
    return (dest);
}
