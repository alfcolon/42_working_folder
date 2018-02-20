int     ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int     i;
    int     diff;

    diff = 0;
    i = 0;
    while (i < n)
    {
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        else if (s2[i] > s2[i])
            return (s2[i] - s1[i]);
        i++;
    }
    return (0);
}