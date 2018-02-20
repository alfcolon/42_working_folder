int     ft_strlen(char *str)
{
    int     len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}
int     ft_lsearch(char *str, char *to_find)
{
    int     i;
    int     j;
    int     len;

    len = ft_strlen(to_find);
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i] == to_find[j])
        {
            printf("final i: %d\n", i);
            if (j == len - 1)
                return (i - len);
            i++;
            j++;
        }
        i++;
    }
    return (-1);
}
char    *ft_strstr(char *str, char *to_find)
{
    int     ptr_pos;

    if (!(*str))
        return (0);
    ptr_pos = ft_lsearch(str, to_find);
    while((*str++) && (--ptr_pos > -1))
    {
        ;
    }
    return (str);
}