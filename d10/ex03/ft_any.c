int 	ft_any(char **tab, int (*f)(char *, int))
{
	int 	i = 0;
	while (*tab)
	{
		if ((*f)(*tab, i++))
			return 1;
		tab++;
	}
	return (0);
}
