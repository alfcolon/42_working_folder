int     ft_strcmp(char *s1, char *s2)
{
    int     i;
    int     diff;

    diff = 0;
    i = 0;
    while ((s1[i]) || (s2[i]))
    {
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        else if (s2[i] > s2[i])
            return (s2[i] - s1[i]);
        i++;
    }
    return (0);
}