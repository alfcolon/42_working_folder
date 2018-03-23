int		ft_count_if(char **tab, int (*f)(char *))
{
	int		count;

	count = 0;
	while (tab)
	{
		if ((*f)(**tab))
			count++;
		tab++;
	}
	return count;
}
