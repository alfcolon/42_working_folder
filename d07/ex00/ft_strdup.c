char    *ft_strcpy(char *dest, char *src)
{
    while (*dest++ = *src++)
    {
        ;
    }
    return (dest);
}
int     ft_strlen(char *str)
{
    int     len;

    len = 0;
    while (str[len])
    {
        len++;
    }
}
char    *ft_strdup(char *str)
{
    int     len;

    char  *dest = (char *)malloc(sizeof(str) * ft_strlen(str));
    ft_strcpy(dest, str);
    printf("dest:%s", dest);
    return (dest);
}
